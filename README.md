# 网格简化作业

2022秋实时三维图形基础课小作业之一，复现Surface Simplification Using Quadric Error Metrics

[原论文](https://www.cs.cmu.edu/~./garland/Papers/quadrics.pdf)

## 目录结构

基于课程提供的框架（这个框架好像很大程度上来自于中科大的图形学课...?）。本项目目录包含以下若干子目录：

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

***
实现效果：./网格简化.mp4  
(这之后还改了些bug，但没再录.)

<video src="网格简化.mp4" controls="controls" width="500" height="300"></video>