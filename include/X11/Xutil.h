/*
 * Minimal X11/Xutil.h stub — XVisualInfo + XGetVisualInfo.
 * The real libX11.so is resolved at runtime on the target rootfs.
 */
#ifndef _XUTIL_H_
#define _XUTIL_H_

#include <X11/Xlib.h>

typedef struct {
    void*         visual;
    XID           visualid;
    int           screen;
    int           depth;
    int           class;
    unsigned long red_mask;
    unsigned long green_mask;
    unsigned long blue_mask;
    int           colormap_size;
    int           bits_per_rgb;
} XVisualInfo;

extern XVisualInfo* XGetVisualInfo(Display* dpy, long mask, XVisualInfo* templ, int* nitems);
extern int XFree(void* data);

#endif /* _XUTIL_H_ */
