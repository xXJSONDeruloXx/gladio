/*
 * Minimal X11/Xlib.h stub — just enough types for GLX.
 * The real libX11.so is resolved at runtime on the target rootfs.
 */
#ifndef _XLIB_H_
#define _XLIB_H_

typedef unsigned long XID;
typedef XID Window;
typedef XID Pixmap;
typedef XID Font;
typedef int Bool;
typedef int Status;
typedef struct _XDisplay Display;

#define True  1
#define False 0

/* XGetVisualInfo mask bits */
#define VisualDepthMask  0x08
#define VisualClassMask  0x04

/* Visual classes */
#define TrueColor 4

#endif /* _XLIB_H_ */
