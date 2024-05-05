# 3. 网格简化 MeshSimplification

欢迎大家来到第三次作业！

**请不要在目录中包含中文字符！**

## 作业提交

- 提交内容：程序代码和实验报告PPT
- 提交位置：<https://bhpan.buaa.edu.cn:443/link/EF84F760A8C76CF8893D19196C7A378B>的“第三次作业”子目录下， 密码`5XIu`。

## 目录结构

本项目目录包含以下若干子目录：

- _deps/: `U`开头的依赖项
- data/: 见下
  - models/: 作业所需的三维模型文件
  - shaders/: 着色器文件，其中部分文件需要大家填写补充
- include/_deps/: stb_image.h，供图像处理使用
- src/: 本次作业项目的源代码
  - _deps/eigen: EIGEN库的头文件 
  - app/: 主要部分的代码
    - main.cpp: 和上一次作业框架基本相同，用于渲染展示，无需修改
    - MeshSimplification.cpp: 请大家完成这一文件中的函数
  - tool/: 工具代码，包括三维模型加载、摄像机移动

## 作业要求
填写`MeshSimpification.cpp`的`simplifyMesh`函数，以完成基于二次误差的网格简化功能。

## 作业指导

对于这个问题，可以参考<https://blog.csdn.net/u010669231/article/details/104450059>中的方法。建议读懂代码，并用Eigen库的定义方法重新完成。

对于Eigen的用法，可以参考[教程](https://www.cnblogs.com/houkai/p/6347408.html)、[文档](https://github.com/qixianyu-buaa/EigenChineseDocument)编写代码。

需要填写的内容包括：
1. 为每个节点计算$Q$矩阵：$Q=\sum_{plane(v_a)}K_p$
14. 为点对计算节点间消耗(建议采用std::priority_queue\<std::tuple\>存储，方便后续收缩。可参考[教程](https://blog.csdn.net/qq_41791510/article/details/114854303)，[文档](https://zh.cppreference.com/w/cpp/container/priority_queue))
514. 收缩节点，直到达到所需比例


## 用户手册

依然可以使用鼠标或键盘调整摄像机视角来漫游场景。

通过左右键可以反复执行网格简化效果，供大家对比调试。


