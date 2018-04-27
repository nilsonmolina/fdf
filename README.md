# 42 Project: `fdf`

## Objective
*In this project you will discover the basics of graphic programming, and in particular how to place points in space, how to join them with segments and most importantly how to observe the scene from a particular viewpoint.   You will also discover your first graphic library: miniLibX. This library was developedninternally and includes the minimum necessary to open a window, light a pixel and deal with events linked to this window: keyboard and mouse. This project also introduces you to “events” programming. Don’t forget to watch the e-learning videos!*

## MiniLibx
MiniLibx is an in house graphics library for students at 42 to cry and curse over.  The documentation is pretty limited, the provided library is out of date, but that is all part of the learning process.  First things first, go to this beautiful page for much more information than I could ever hope to provide on this topic:

Link from Andy:  
https://github.com/qst0/ft_libgfx

The Minilibx library provided on the project page of 42, will not work on macOS Sierra or newer, but fortunately, you will find an updated one here.  This is also a treasure trove of information and I recommend you spend more time there than you do here.

But after that, you can consider taking a quick look at my `_resources/basics` folder. In it, I have included a few examples of a lot of the basics to get things rolling.  As a disclaimer, I wrote these when I was learning how to use MiniLibX and they are just simple attempts at testing things out. They do NOT have any best practices, they ARE very rudimentary, and there WILL be mistsakes in them. But this is how I started learning, and hopefully it may help you as well.
1. [Put Pixel](./_resources/_basics/01-put-pixel/main.c)  
    In this example, I simply open an mlx window of a predetermined size (400x400 pixels) and draw a 100 by 100 pixel square. A lot of what you see here is the basis of all minilibx projects.
1. [Events](./_resources/_basics/02-events/main.c)  
    Now we move on to listening to user events, like a key press or a mouse click.  These are obviously very basic examples, but you can do a lot with this.  My final version of fdf utilizes other "hooks" to detect key holding, which is described in more detail at the github resource provided above.
1. [Clear Window](./_resources/_basics/03-clear-window/main.c)  
    Now you obviously want your images to change, and one step is to actually clear what is onscreen before you start drawing your next image.  This was a simple attempt at doing just that.
1. [Clear Draw](./_resources/_basics/04-clear-draw/main.c)  
    Very similar to the previous one, however I start testing out pointers instead. Once again, I clear the image using mouse click and key press events.
1. [Put Image](./_resources/_basics/05-put-image/main.c)  
    Now we move onto more advanced topics.  Rather than using the built in 'mlx_pixel_put', we start dealing with mlx images by getting it's data address, adding colors to different locations in that data address, and finally putting the image in the mlx window.
1. [General Improvements](./_resources/_basics/06-improved/)   
    In here, I just make a few general improvements to the previous example.  I start better organizing the code and cleaning up a few unneccesary things.
1. [GNL vs Buffer](./_resources/_basics/07-gnl-vs-buffer/)    
    This is a more complete project and me testing different implementations for fdf.  There are definitely bugs in here, as this was just a backup of my fdf code, before moving forward.

# Bresenham's Line Algorithm
For fdf, we will be given a number of points to draw our wireframes from, but we will eventually need to draw lines between these points.  While algorithms such as Wu's algorithm are also frequently used in modern computer graphics (thanks to it's support of antialiasing), the speed and simplicity of Bresenham's line algorithm means that it is still important today. It is commonly used to draw line primitives in a bitmap image (e.g. on a computer screen), as it uses only integer addition, subtraction and bit shifting, all of which are very cheap operations in standard computer architectures. It is one of the earliest algorithms developed in the field of computer graphics and thanks to it's simplicity, it is often implemented in either the firmware or the graphics hardware of modern graphics cards.

Below is a C implementation of Bresenham's Line Algorithm.  Note that this will NOT pass the 42 Norminette, but making the changes should be simple enough!
```c
// Instead of swaps in the initialisation, use error 
// calculation for both directions x and y simultaneously 
void line(int x0, int y0, int x1, int y1) {
 
  int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
  int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1; 
  int err = (dx>dy ? dx : -dy)/2, e2;
 
  for(;;){
    setPixel(x0,y0);
    if (x0==x1 && y0==y1) break;
    e2 = err;
    if (e2 >-dx) { err -= dy; x0 += sx; }
    if (e2 < dy) { err += dx; y0 += sy; }
  }
}
```
References:  
- [Algorithm Examples](http://rosettacode.org/wiki/Bitmap/Bresenham%27s_line_algorithm)
- [Technical PDF](http://www.idav.ucdavis.edu/education/GraphicsNotes/CppNotes/Inline-Functions/CAGDNotes/Bresenhams-Algorithm.pdf)

# Rotating Objects
## Writing a rotate function
```c
var rotateZ3D = function(theta) {
    var sin_t = sin(theta);
    var cos_t = cos(theta);
    
    for (var n = 0; n < nodes.length; n++) {
        var node = nodes[n];
        var x = node[0];
        var y = node[1];
        node[0] = x * cos_t - y * sin_t;
        node[1] = y * cos_t + x * sin_t;
    }
};
```
This function loops through all the nodes in the node array, finds its current x and y coordinates and then updates them. We find sin(theta) and cos(theta) outside the loop so we only need to calculate it once.

## Rotating in three dimensions
We can now rotate our cube in two dimensions, but it still looks like a square. What if we want to rotate our cube around the y-axis (veritcal axis). If we imagine looking down on our cube as we rotate it around the y-axis, what we would see is a rotating square, just like we do when we rotate about the z-axis.

So if we imagine our relabelling our axes, so the z-axis becomes the y-axis, we can come up with a new function for rotating around the y-axis. In this case, the y-coordinates of the node do not change.
```c
var rotateY3D = function(theta) {
    var sin_t = sin(theta);
    var cos_t = cos(theta);
    
    for (var n = 0; n < nodes.length; n++) {
        var node = nodes[n];
        var x = node[0];
        var z = node[2];
        node[0] = x * cos_t - z * sin_t;
        node[2] = z * cos_t + x * sin_t;
    }
};
```
And we can use the same argument to create a function that rotates our cube around the x-axis:
```c
var rotateX3D = function(theta) {
    var sin_t = sin(theta);
    var cos_t = cos(theta);
    
    for (var n = 0; n < nodes.length; n++) {
        var node = nodes[n];
        var y = node[1];
        var z = node[2];
        node[1] = y * cos_t - z * sin_t;
        node[2] = z * cos_t + y * sin_t;
    }
};
```

Reference:  
http://petercollingridge.appspot.com/3D-tutorial/rotating-objects

## Hex Colors
The colors provided in some of the maps for fdf are in Hexadecimal.  The below link can provide a very quick and rudimentary understanding of how hex-colors work.

Reference:  
https://www.mathsisfun.com/hexadecimal-decimal-colors.html

## fsanitize error:
```bash
==75210==AddressSanitizer CHECK failed: /BuildRoot/Library/Caches/com.apple.xbs/Sources/clang_compiler_rt/clang-900.0.39.2/src/projects/compiler-rt/lib/asan/asan_allocator.cc:137 "((m->chunk_state)) == ((CHUNK_QUARANTINE))" (0x0, 0x3)
    #0 0x10e069f5f in __asan::AsanCheckFailed(char const*, int, char const*, unsigned long long, unsigned long long) (libclang_rt.asan_osx_dynamic.dylib:x86_64h+0x60f5f)
    #1 0x10e0811f7 in __sanitizer::CheckFailed(char const*, int, char const*, unsigned long long, unsigned long long) (libclang_rt.asan_osx_dynamic.dylib:x86_64h+0x781f7)
    #2 0x10e00e752 in __asan::QuarantineCallback::Recycle(__asan::AsanChunk*) (libclang_rt.asan_osx_dynamic.dylib:x86_64h+0x5752)
    #3 0x10e00e441 in __sanitizer::Quarantine<__asan::QuarantineCallback, __asan::AsanChunk>::DoRecycle(__sanitizer::QuarantineCache<__asan::QuarantineCallback>*, __asan::QuarantineCallback) (libclang_rt.asan_osx_dynamic.dylib:x86_64h+0x5441)
    #4 0x10e00e315 in __sanitizer::Quarantine<__asan::QuarantineCallback, __asan::AsanChunk>::Recycle(__asan::QuarantineCallback) (libclang_rt.asan_osx_dynamic.dylib:x86_64h+0x5315)
    #5 0x10e010d3b in __sanitizer::Quarantine<__asan::QuarantineCallback, __asan::AsanChunk>::Put(__sanitizer::QuarantineCache<__asan::QuarantineCallback>*, __asan::QuarantineCallback, __asan::AsanChunk*, unsigned long) (libclang_rt.asan_osx_dynamic.dylib:x86_64h+0x7d3b)
    #6 0x10e062130 in wrap_free (libclang_rt.asan_osx_dynamic.dylib:x86_64h+0x59130)
    #7 0x10dfe3c17 in mlx_destroy_image (fdf:x86_64+0x10000ec17)
    #8 0x10dfd7f4d in clear_img render.c:17
    #9 0x10dfda8fb in put_img_map render.c:86
    #10 0x10dfdfbb5 in rotate_axis mutate.c:26
    #11 0x10dfd78ce in key_hold events.c:36
    #12 0x7fff2e04a028 in -[NSWindow(NSEventRouting) _reallySendEvent:isDelayedEvent:] (AppKit:x86_64+0x976028)
    #13 0x7fff2e04885b in -[NSWindow(NSEventRouting) sendEvent:] (AppKit:x86_64+0x97485b)
    #14 0x7fff2dea9fa2 in -[NSApplication(NSEvent) sendEvent:] (AppKit:x86_64+0x7d5fa2)
    #15 0x7fff2d70ad9c in -[NSApplication run] (AppKit:x86_64+0x36d9c)
    #16 0x10dfe33c5 in mlx_loop (fdf:x86_64+0x10000e3c5)
    #17 0x10dfd6f60 in fdf main.c:36
    #18 0x10dfd757d in main main.c:42
    #19 0x7fff57a5e114 in start (libdyld.dylib:x86_64+0x1114)
```