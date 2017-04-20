// VectorMath.cpp
//

#include "stdafx.h"
#include <math.h>

#ifdef __APPLE__

#include <GLUT/glut.h>

#else

#include <GL/glut.h>

#endif


#include "gltools_extracted.h"

#include "VectorMath.h"
#define LZZ_INLINE inline
void gltAddVectors (GLTVector3 const vFirst, GLTVector3 const vSecond, GLTVector3 vResult)
                                                                                          {
    vResult[0] = vFirst[0] + vSecond[0];
    vResult[1] = vFirst[1] + vSecond[1];
    vResult[2] = vFirst[2] + vSecond[2];
    }
void gltSubtractVectors (GLTVector3 const vFirst, GLTVector3 const vSecond, GLTVector3 vResult)
    {
    vResult[0] = vFirst[0] - vSecond[0];
    vResult[1] = vFirst[1] - vSecond[1];
    vResult[2] = vFirst[2] - vSecond[2];
    }
void gltScaleVector (GLTVector3 vVector, GLfloat const fScale)
    { 
    vVector[0] *= fScale; vVector[1] *= fScale; vVector[2] *= fScale; 
    }
GLfloat gltGetVectorLengthSqrd (GLTVector3 const vVector)
    { 
    return (vVector[0]*vVector[0]) + (vVector[1]*vVector[1]) + (vVector[2]*vVector[2]); 
    }
GLfloat gltGetVectorLength (GLTVector3 const vVector)
    { 
    return (GLfloat)sqrt(gltGetVectorLengthSqrd(vVector)); 
    }
void gltNormalizeVector (GLTVector3 vNormal)
    { 
    GLfloat fLength = 1.0f / gltGetVectorLength(vNormal);
    gltScaleVector(vNormal, fLength); 
    }
void gltCopyVector (GLTVector3 const vSource, GLTVector3 vDest)
    { 
    memcpy(vDest, vSource, sizeof(GLTVector3)); 
    }
GLfloat gltVectorDotProduct (GLTVector3 const vU, GLTVector3 const vV)
    {
    return vU[0]*vV[0] + vU[1]*vV[1] + vU[2]*vV[2]; 
    }
void gltVectorCrossProduct (GLTVector3 const vU, GLTVector3 const vV, GLTVector3 vResult)
        {
	vResult[0] = vU[1]*vV[2] - vV[1]*vU[2];
	vResult[1] = -vU[0]*vV[2] + vV[0]*vU[2];
	vResult[2] = vU[0]*vV[1] - vV[0]*vU[1];
	}
void gltGetNormalVector (GLTVector3 const vP1, GLTVector3 const vP2, GLTVector3 const vP3, GLTVector3 vNormal)
    {
    GLTVector3 vV1, vV2;
    
    gltSubtractVectors(vP2, vP1, vV1);
    gltSubtractVectors(vP3, vP1, vV2);
    
    gltVectorCrossProduct(vV1, vV2, vNormal);
    gltNormalizeVector(vNormal);
    }
void gltTransformPoint (GLTVector3 const vSrcVector, GLTMatrix const mMatrix, GLTVector3 vOut)
    {
    vOut[0] = mMatrix[0] * vSrcVector[0] + mMatrix[4] * vSrcVector[1] + mMatrix[8] *  vSrcVector[2] + mMatrix[12];
    vOut[1] = mMatrix[1] * vSrcVector[0] + mMatrix[5] * vSrcVector[1] + mMatrix[9] *  vSrcVector[2] + mMatrix[13];
    vOut[2] = mMatrix[2] * vSrcVector[0] + mMatrix[6] * vSrcVector[1] + mMatrix[10] * vSrcVector[2] + mMatrix[14];    
    }
void gltRotateVector (GLTVector3 const vSrcVector, GLTMatrix const mMatrix, GLTVector3 vOut)
    {
    vOut[0] = mMatrix[0] * vSrcVector[0] + mMatrix[4] * vSrcVector[1] + mMatrix[8] *  vSrcVector[2];
    vOut[1] = mMatrix[1] * vSrcVector[0] + mMatrix[5] * vSrcVector[1] + mMatrix[9] *  vSrcVector[2];
    vOut[2] = mMatrix[2] * vSrcVector[0] + mMatrix[6] * vSrcVector[1] + mMatrix[10] * vSrcVector[2];    	
    }
void gltGetPlaneEquation (GLTVector3 vPoint1, GLTVector3 vPoint2, GLTVector3 vPoint3, GLTVector3 vPlane)
    {
    // Get normal vector from three points. The normal vector is thl vector is the first three coefficients
    // to the plane equation...
    gltGetNormalVector(vPoint1, vPoint2, vPoint3, vPlane);
    
    // Final coefficient found by back substitution
    vPlane[3] = -(vPlane[0] * vPoint3[0] + vPlane[1] * vPoint3[1] + vPlane[2] * vPoint3[2]);
    }
GLfloat gltDistanceToPlane (GLTVector3 vPoint, GLTVector4 vPlane)
    {
    return vPoint[0]*vPlane[0] + vPoint[1]*vPlane[1] + vPoint[2]*vPlane[2] + vPlane[3];
    }
#undef LZZ_INLINE
