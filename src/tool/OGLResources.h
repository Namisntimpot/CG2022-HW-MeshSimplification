#pragma once
#include <Eigen/Dense>
#include <UGL/UGL>

namespace Ubpa
{
	namespace tool {
		class OGLResources {
		public:
			~OGLResources();
			gl::VertexArray* va{ nullptr };
			std::map<std::string, gl::VertexBuffer*> name2vb;
			gl::ElementBuffer* eb{ nullptr };
			std::vector<Eigen::Vector3f> positions;
			std::vector<normalf> normals;
			std::vector<Eigen::Vector3i> indices;

			static OGLResources* LoadObj(const std::string& path);
			static OGLResources* fromMesh(std::vector<Eigen::Vector3f>&& positions, std::vector<Eigen::Vector3i>&& indices);
			static OGLResources* fromMesh(const std::vector<Eigen::Vector3f>& positions, const std::vector<Eigen::Vector3i>& indices);
		};

		
	}
}
