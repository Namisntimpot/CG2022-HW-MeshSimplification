#include "OGLResources.h"

#include <fstream>
#include <sstream>
#include <random>

using namespace Ubpa;
using namespace std;
namespace Ubpa
{
namespace tool {
	vector<normalf> GenNormal(const vector<Eigen::Vector3f>& positions, const vector<Eigen::Vector3i>& indices);

	OGLResources::~OGLResources() {
		delete va;
		delete eb;
		for (const auto& [name, vb] : name2vb)
			delete vb;
	}

	OGLResources* OGLResources::LoadObj(const std::string& path) {
		// [read file to buffer]
		ifstream objfile(path, ios::in | ios::ate);
		if (!objfile.is_open()) {
			cout << "ERROR::SimpleLoader::LoadObj:" << endl
				<< "\t" << "open file (" << path << ") fail" << endl;
			return nullptr;
		}

		size_t size = objfile.tellg();
		objfile.seekg(0, ios::beg);
		char* buffer = new char[size + 1];
		buffer[size] = 0;
		objfile.read(buffer, size);
		objfile.close();

		// [buffer to lines]
		vector<string> lines;
		size_t i = 0;
		while (i <= size) {
			size_t j = 0;
			while ((buffer[i + j] != '\n') && (buffer[i + j] != '\0'))
				j++;
			lines.emplace_back(buffer + i, j);
			i += j + 1;
		}
		delete[] buffer;
		buffer = nullptr;

		/*for (const auto& line : lines)
			cout << line << endl;*/

			// [decode]
		vector<Eigen::Vector3f> positions;
		vector<normalf> normals;
		vector<pointf2> texcoords;
		vector<Eigen::Vector3i> indices;
		vector<vecf3> tangents;
		for (auto line : lines) {
			if (line.empty() || line == "\n")
				continue;
			stringstream ss(line);
			string id;
			ss >> id;
			if (id == "v") {
				pointf3 pos;
				ss >> pos;
				positions.emplace_back(Eigen::Vector3f(pos[0], pos[1], pos[2]));
			}
			else if (id == "f") {
				vali3 tri;
				ss >> tri;
				indices.emplace_back(Eigen::Vector3i{tri[0] - 1,tri[1] - 1,tri[2] - 1});
			}
			else if (id == "vn") {
				normalf n;
				ss >> n;
				normals.push_back(n.normalize());
			}
			else if (id == "vt") {
				pointf2 uv;
				ss >> uv;
				texcoords.push_back(uv);
			}
		}

		auto rst = new OGLResources;

		// [offset, scale positions]
		bboxf3 box;
		for (const auto& pos : positions)
			box.combine_to_self(pointf3(pos[0], pos[1], pos[2]));
		auto center = box.center();
		float scale = sqrt(3.f / box.diagonal().norm2());
		for (auto& pos : positions)
		{
			auto posU = (scale * (pointf3(pos[0], pos[1], pos[2]) - center));
			pos = Eigen::Vector3f(posU[0], posU[1], posU[2]);
		}



		// [generate texcoords, normals, tangents]
		if (normals.empty())
			normals = GenNormal(positions, indices);

		// [generate VAO, VBO, EBO]
		auto vb_pos = new gl::VertexBuffer(positions.size() * sizeof(pointf3), positions[0].data());
		auto vb_n = new gl::VertexBuffer(normals.size() * sizeof(normalf), normals[0].data());
		auto eb = new gl::ElementBuffer(gl::BasicPrimitiveType::Triangles, indices.size(), (GLuint*)indices.data());

		gl::VertexArray::Format format;
		format.attrptrs.push_back(vb_pos->AttrPtr(3, gl::DataType::Float, false, sizeof(pointf3)));
		format.attrptrs.push_back(vb_n->AttrPtr(3, gl::DataType::Float, false, sizeof(normalf)));
		format.eb = eb;

		rst->name2vb["pos"] = vb_pos;
		rst->name2vb["n"] = vb_n;
		rst->eb = eb;
		rst->va = new gl::VertexArray({ 0,1 }, format);
		rst->positions = move(positions);
		rst->normals = move(normals);
		rst->indices = move(indices);

		return rst;
	}

	OGLResources* OGLResources::fromMesh(vector<Eigen::Vector3f>&& positions, vector<Eigen::Vector3i>&& indices) {

		auto rst = new OGLResources;

		// [generate VAO, VBO, EBO]
		auto normals = GenNormal(positions, indices);
		auto vb_pos = new gl::VertexBuffer(positions.size() * sizeof(pointf3), positions[0].data());
		auto vb_n = new gl::VertexBuffer(normals.size() * sizeof(normalf), normals[0].data());
		auto eb = new gl::ElementBuffer(gl::BasicPrimitiveType::Triangles, indices.size(), (GLuint*)indices.data());

		gl::VertexArray::Format format;
		format.attrptrs.push_back(vb_pos->AttrPtr(3, gl::DataType::Float, false, sizeof(pointf3)));
		format.attrptrs.push_back(vb_n->AttrPtr(3, gl::DataType::Float, false, sizeof(normalf)));
		format.eb = eb;

		rst->name2vb["pos"] = vb_pos;
		rst->name2vb["n"] = vb_n;
		rst->eb = eb;
		rst->va = new gl::VertexArray({ 0,1 }, format);
		rst->positions = move(positions);
		rst->normals = move(normals);
		rst->indices = move(indices);

		return rst;
	}

	OGLResources* OGLResources::fromMesh(const vector<Eigen::Vector3f>& positions, const vector<Eigen::Vector3i>& indices) {

		 auto rst = new OGLResources;

		 // [generate VAO, VBO, EBO]
		 auto normals = GenNormal(positions, indices);
		 auto vb_pos = new gl::VertexBuffer(positions.size() * sizeof(pointf3), positions[0].data());
		 auto vb_n = new gl::VertexBuffer(normals.size() * sizeof(normalf), normals[0].data());
		 auto eb = new gl::ElementBuffer(gl::BasicPrimitiveType::Triangles, indices.size(), (GLuint*)indices.data());

		 gl::VertexArray::Format format;
		 format.attrptrs.push_back(vb_pos->AttrPtr(3, gl::DataType::Float, false, sizeof(pointf3)));
		 format.attrptrs.push_back(vb_n->AttrPtr(3, gl::DataType::Float, false, sizeof(normalf)));
		 format.eb = eb;

		 rst->name2vb["pos"] = vb_pos;
		 rst->name2vb["n"] = vb_n;
		 rst->eb = eb;
		 rst->va = new gl::VertexArray({ 0,1 }, format);
		 rst->positions = positions;
		 rst->normals = move(normals);
		 rst->indices = indices;

		 return rst;
	 }

	vector<normalf> GenNormal(const vector<Eigen::Vector3f>& positions, const vector<Eigen::Vector3i>& indices) {
		vector<normalf> wNs(positions.size(), normalf{ 0.f });
		for (size_t i = 0; i < indices.size(); i++) {
			size_t idx0 = indices[i][0];
			size_t idx1 = indices[i][1];
			size_t idx2 = indices[i][2];
			const auto& p0 = positions[idx0];
			const auto& p1 = positions[idx1];
			const auto& p2 = positions[idx2];
			auto v01 = p1 - p0;
			auto v02 = p2 - p0;
			auto wNE = v01.cross(v02);
			auto wN = normalf{ wNE[0],wNE[1],wNE[2] };
			wNs[idx0] += wN;
			wNs[idx1] += wN;
			wNs[idx2] += wN;
		}
		for (auto& n : wNs)
			if (n.norm() > 0)
				n.normalize_self();
		return wNs;
	}

}
}
