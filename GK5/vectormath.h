// VectorMath.h
//

#ifndef LZZ_VectorMath_h

#ifdef __APPLE__

#include <GLUT/glut.h>

#else

#include <GL/glut.h>

#include "gltools_extracted.h"

#endif
#define LZZ_VectorMath_h
#define LZZ_INLINE inline
void gltAddVectors (GLTVector3 const vFirst, GLTVector3 const vSecond, GLTVector3 vResult);
void gltSubtractVectors (GLTVector3 const vFirst, GLTVector3 const vSecond, GLTVector3 vResult);
void gltScaleVector (GLTVector3 vVector, GLfloat const fScale);
GLfloat gltGetVectorLengthSqrd (GLTVector3 const vVector);
GLfloat gltGetVectorLength (GLTVector3 const vVector);
void gltNormalizeVector (GLTVector3 vNormal);
void gltCopyVector (GLTVector3 const vSource, GLTVector3 vDest);
GLfloat gltVectorDotProduct (GLTVector3 const vU, GLTVector3 const vV);
void gltVectorCrossProduct (GLTVector3 const vU, GLTVector3 const vV, GLTVector3 vResult);
void gltGetNormalVector (GLTVector3 const vP1, GLTVector3 const vP2, GLTVector3 const vP3, GLTVector3 vNormal);
void gltTransformPoint (GLTVector3 const vSrcVector, GLTMatrix const mMatrix, GLTVector3 vOut);
void gltRotateVector (GLTVector3 const vSrcVector, GLTMatrix const mMatrix, GLTVector3 vOut);
void gltGetPlaneEquation (GLTVector3 vPoint1, GLTVector3 vPoint2, GLTVector3 vPoint3, GLTVector3 vPlane);
GLfloat gltDistanceToPlane (GLTVector3 vPoint, GLTVector4 vPlane);
#undef LZZ_INLINE
#endif
