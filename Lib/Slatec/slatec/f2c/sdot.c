/* sdot.f -- translated by f2c (version 20060506).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include "f2c.h"

/* DECK SDOT */
doublereal sdot_(integer *n, real *sx, integer *incx, real *sy, integer *incy)
{
    /* System generated locals */
    integer i__1, i__2;
    real ret_val;

    /* Local variables */
    static integer i__, m, ix, iy, ns, mp1;

/* ***BEGIN PROLOGUE  SDOT */
/* ***PURPOSE  Compute the inner product of two vectors. */
/* ***LIBRARY   SLATEC (BLAS) */
/* ***CATEGORY  D1A4 */
/* ***TYPE      SINGLE PRECISION (SDOT-S, DDOT-D, CDOTU-C) */
/* ***KEYWORDS  BLAS, INNER PRODUCT, LINEAR ALGEBRA, VECTOR */
/* ***AUTHOR  Lawson, C. L., (JPL) */
/*           Hanson, R. J., (SNLA) */
/*           Kincaid, D. R., (U. of Texas) */
/*           Krogh, F. T., (JPL) */
/* ***DESCRIPTION */

/*                B L A S  Subprogram */
/*    Description of Parameters */

/*     --Input-- */
/*        N  number of elements in input vector(s) */
/*       SX  single precision vector with N elements */
/*     INCX  storage spacing between elements of SX */
/*       SY  single precision vector with N elements */
/*     INCY  storage spacing between elements of SY */

/*     --Output-- */
/*     SDOT  single precision dot product (zero if N .LE. 0) */

/*     Returns the dot product of single precision SX and SY. */
/*     SDOT = sum for I = 0 to N-1 of  SX(LX+I*INCX) * SY(LY+I*INCY), */
/*     where LX = 1 if INCX .GE. 0, else LX = 1+(1-N)*INCX, and LY is */
/*     defined in a similar way using INCY. */

/* ***REFERENCES  C. L. Lawson, R. J. Hanson, D. R. Kincaid and F. T. */
/*                 Krogh, Basic linear algebra subprograms for Fortran */
/*                 usage, Algorithm No. 539, Transactions on Mathematical */
/*                 Software 5, 3 (September 1979), pp. 308-323. */
/* ***ROUTINES CALLED  (NONE) */
/* ***REVISION HISTORY  (YYMMDD) */
/*   791001  DATE WRITTEN */
/*   890831  Modified array declarations.  (WRB) */
/*   890831  REVISION DATE from Version 3.2 */
/*   891214  Prologue converted to Version 4.0 format.  (BAB) */
/*   920310  Corrected definition of LX in DESCRIPTION.  (WRB) */
/*   920501  Reformatted the REFERENCES section.  (WRB) */
/* ***END PROLOGUE  SDOT */
/* ***FIRST EXECUTABLE STATEMENT  SDOT */
    /* Parameter adjustments */
    --sy;
    --sx;

    /* Function Body */
    ret_val = 0.f;
    if (*n <= 0) {
	return ret_val;
    }
    if (*incx == *incy) {
	if ((i__1 = *incx - 1) < 0) {
	    goto L5;
	} else if (i__1 == 0) {
	    goto L20;
	} else {
	    goto L60;
	}
    }

/*     Code for unequal or nonpositive increments. */

L5:
    ix = 1;
    iy = 1;
    if (*incx < 0) {
	ix = (-(*n) + 1) * *incx + 1;
    }
    if (*incy < 0) {
	iy = (-(*n) + 1) * *incy + 1;
    }
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ret_val += sx[ix] * sy[iy];
	ix += *incx;
	iy += *incy;
/* L10: */
    }
    return ret_val;

/*     Code for both increments equal to 1. */

/*     Clean-up loop so remaining vector length is a multiple of 5. */

L20:
    m = *n % 5;
    if (m == 0) {
	goto L40;
    }
    i__1 = m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ret_val += sx[i__] * sy[i__];
/* L30: */
    }
    if (*n < 5) {
	return ret_val;
    }
L40:
    mp1 = m + 1;
    i__1 = *n;
    for (i__ = mp1; i__ <= i__1; i__ += 5) {
	ret_val = ret_val + sx[i__] * sy[i__] + sx[i__ + 1] * sy[i__ + 1] + 
		sx[i__ + 2] * sy[i__ + 2] + sx[i__ + 3] * sy[i__ + 3] + sx[
		i__ + 4] * sy[i__ + 4];
/* L50: */
    }
    return ret_val;

/*     Code for equal, positive, non-unit increments. */

L60:
    ns = *n * *incx;
    i__1 = ns;
    i__2 = *incx;
    for (i__ = 1; i__2 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += i__2) {
	ret_val += sx[i__] * sy[i__];
/* L70: */
    }
    return ret_val;
} /* sdot_ */

