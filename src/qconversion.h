/*
 * This file is part of xrayutilities.
 *
 * xrayutilities is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright (C) 2013 Dominik Kriegner <dominik.kriegner@gmail.com>
*/

#ifndef _qconversion_h_
#define _qconversion_h_

#define M_PI 3.14159265358979323846
#define M_2PI (2*M_PI)

#define cdeg2rad (M_PI/180.)
#define crad2deg (180./M_PI)

#define deg2rad(ang) (ang*cdeg2rad)
#define rad2deg(rad) (rad*crad2deg)

#define INLINE extern inline
#define RESTRICT restrict

/* ###################################
 * matrix vector operations for
 * 3x3 matrices and vectors of length
 * 3
 * ################################### */

INLINE void ident(double *m) __attribute__((always_inline));

INLINE void sumvec(double *RESTRICT v1,double *RESTRICT v2) __attribute__((always_inline));

INLINE void diffvec(double *RESTRICT v1,double *RESTRICT v2) __attribute__((always_inline));

INLINE double norm(double *v) __attribute__((always_inline));

INLINE void normalize(double *v) __attribute__((always_inline));

INLINE void veccopy(double *RESTRICT v1, double *RESTRICT v2) __attribute__((always_inline));

INLINE void vecmul(double *RESTRICT r, double a) __attribute__((always_inline));

INLINE void cross(double *RESTRICT v1, double *RESTRICT v2, double *RESTRICT r) __attribute__((always_inline));

INLINE void vecmatcross(double *RESTRICT v, double *RESTRICT m, double *RESTRICT mr) __attribute__((always_inline));

INLINE void matmul(double *RESTRICT m1, double *RESTRICT m2) __attribute__((always_inline));

INLINE void matmulc(double *RESTRICT m, double c) __attribute__((always_inline));

INLINE void matvec(double *RESTRICT m, double *RESTRICT v, double *RESTRICT r) __attribute__((always_inline));

INLINE void tensorprod(double *RESTRICT v1, double *RESTRICT v2, double *RESTRICT m) __attribute__((always_inline));

INLINE void summat(double *RESTRICT m1,double *RESTRICT m2) __attribute__((always_inline));

INLINE void diffmat(double *RESTRICT m1,double *RESTRICT m2) __attribute__((always_inline));

INLINE void inversemat(double *RESTRICT m, double *RESTRICT i) __attribute__((always_inline));

INLINE double determinant(double *RESTRICT m) __attribute__((always_inline));


/*##############################################
#   functions which implement rotation matrices
#   for all coordinate axes and rotation senses
#
#   the routines expect angles in radians
#   for conversion from degrees to radians
#   the functions and2rad and rad2ang are
#   supplied
################################################*/

typedef void (*fp_rot)(double,double *);

INLINE void rotation_xp(double a,double *mat) __attribute__((always_inline));
INLINE void rotation_yp(double a,double *mat) __attribute__((always_inline));
INLINE void rotation_zp(double a,double *mat) __attribute__((always_inline));

INLINE void rotation_xm(double a,double *mat) __attribute__((always_inline));
INLINE void rotation_ym(double a,double *mat) __attribute__((always_inline));
INLINE void rotation_zm(double a,double *mat) __attribute__((always_inline));

INLINE void rotation_kappa(double a, double *mat) __attribute__((always_inline));

INLINE void rotation_arb(double a,double *RESTRICT e,double *RESTRICT mat) __attribute__((always_inline));


/*##############################################
#   functions needed for reciprocal space converions
################################################*/

int determine_axes_directions(fp_rot *fp_circles,char *stringAxis,int n);
int determine_detector_pixel(double *rpixel,char *dir, double dpixel, double *r_i, double tilt);
int print_matrix(double *m);
int print_vector(double *m);

#endif

