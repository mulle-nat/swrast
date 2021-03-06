# `#` Software rasterizer

Changes

* moved the X11 dependend `window.h` and `window.c` to `test`
* added an envelope header `swrast.h` file
* renamed `libraster.a` to `libswrast.a`
* added a small error message, if `a.out` can't find the `teapot.3ds` file


Here is the original README:

```
  About
  *****

 To whom it may concern: this directory contains a just-for-fun software
 rasterizer written in C89, started on a boring holiday week when I was sick.

 The entire source code is released into the public domain.

 The rasterizer currently supports the following features:
  - Subpixel correct triangle rasterization
  - Configurable back face culling (cull by vertex winding)
  - Vertex buffers and index buffers
  - Programmable shader pipeline (shaders defined as C functions)
     - Default shaders implement fixed function OpenGL(R) style
       transform & lighting with model view & projection matrix and
       up to 8 independend light sources
  - Perspective correct interpolation of vertex attributes
  - Multpile texture layers with nearest neighbour sampling
  - Depth buffering (OpenGL(R) style comparison function)
  - Alpha blending
  - Multiple framebuffer objects (can be used for e.g. render to texture)
  - viewport mapping
  - OpenGL(R) style depth masking/mapping/clipping
  - Write to color channels can be flagged individually
  - Immediate mode rendering


  Rendering Pipeline
  ******************

     _________________      Vertices are decoded from vertex and index
    | Input Assembler |     buffers. The input assembler stage assembles
    |_________________|     vertices to triangles and walks them through the
            | |             rest of the pipeline.
           _| |_
     ______\___/______      Vertices are transformed with modelview and
    |  Vertex Shader  |     projection matrix. Depending on the shader used,
    |_________________|     vertex lighting values are computed in viewspace.
            | |             Other arbitrary values can be generated that are
           _| |_            later interpolated across the triangle area.
     ______\___/______
    |  Rasterization  |     Pixels are generated from tripples of vertices.
    |_________________|     Vertex attributes are interpolated over the
           _| |_            triangle area.
     ______\___/______
    |    Depth test   |     The interolated depth value is compared to the
    |_________________|     depth buffer value. Pixels are dropped if the
           _| |_            specified comparison opartation returns false.
     ______\___/______
    | Fragment Shader |     The interpolated vertex attributes (e.g. texture
    |_________________|     coordinates) are used to compute a final fragment
           _| |_            color.
     ______\___/______
    |   Framebuffer   |     The final color is (optionally) alpha blended onto
    |     blending    |     framebuffer. Individual color channels can be
    |_________________|     masked out.



  Source code overview
  ********************

 The directory "main" contains the main rasterizer library, currently
 consisting of the following files:

    include/config.h          - Preprocessor defined limits of the
                                rasterization pipeline

    include/predef.h          - Forward declarations of structures

    include/vector.h          - Helper functions for working with
                                four component vectors

    include/color.h           - Helper functions for working with packed
                                four component color values

    include/context.h         - Context structure. Encapsulates all global
    src/context.c               state of the pipeline.

    include/inputassembler.h  - Implementation of the input assembler stage
    src/inputassembler.c

    include/shader.h          - Implementation shader stages
    src/shader.c

    include/rasterizer.h      - Implementation of the rasterizer stage and
    src/rasterizer.c            pixel merging (depth test, texturing
                                and blending)

    include/texture.h         - Implementation of texture objects
    src/texture.c

    include/framebuffer.h     - Implementation of framebuffer objects
    src/framebuffer.c

    include/window.h          - A simple window implementation. Handles a
    src/window.c                window and blits a framebuffer


 The directory "test" contains testing and demo programs, currently consisting
 of the following files:

    3ds.h                     - A quick & dirty 3ds loader for testing
    3ds.c

    test.c                    - A small test program


  Compiling
  *********

 Simply type "make" into the commandline on the top level directory. The
 rasterizer is compiled into a library in the directory "main" and the sample
 programs are compiled to binaries in the "test" directory.

 Type "make clean" to cleanup the directory tree.


  License
  *******

 All source code in this directory is released into the public domain.
 I, David Oberhollenzer, will not assert any copyright claims on the
 documents in this directory.
```

