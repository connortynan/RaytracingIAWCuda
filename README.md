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
* ./raytrace > out.ppm

I struggled to view the output ppm file, but [this website (PPM Viewer)](https://www.cs.rhodes.edu/welshc/COMP141_F16/ppmReader.html) works for me, not sure why nothing else was working

