# RaytracingIAWCuda
Following Raytracing in a Weekend with CUDA, following this tutorial: [https://developer.nvidia.com/blog/accelerated-ray-tracing-cuda/](https://developer.nvidia.com/blog/accelerated-ray-tracing-cuda/)

Next steps are to continue with Peter Shirley's "The Next Week" with the  [RayTracing Repository on github](https://github.com/RayTracing/raytracing.github.io/tree/release)

# Dependencies:
* CUDA supported GPU
* [CUDA Toolkit](https://developer.nvidia.com/cuda-downloads)

# To Run:
* git clone https://github.com/connortynan/RaytracingIAWCuda
* cd ./RaytracingIAWCuda
* nvcc src/main.cu -o raytrace
* ./raytrace
* python3 ppmtopng.py out


# Current output:
![out.png](https://github.com/connortynan/RaytracingIAWCuda/blob/main/out.png)

