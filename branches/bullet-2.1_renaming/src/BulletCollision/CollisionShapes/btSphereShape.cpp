/*
Bullet Continuous Collision Detection and Physics Library
Copyright (c) 2003-2006 Erwin Coumans  http://continuousphysics.com/Bullet/

This software is provided 'as-is', without any express or implied warranty.
In no event will the authors be held liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose, 
including commercial applications, and to alter it and redistribute it freely, 
subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/

#include "btSphereShape.h"
#include "BulletCollision/CollisionShapes/btCollisionMargin.h"

#include "LinearMath/btQuaternion.h"


btSphereShape ::btSphereShape (btScalar radius)
: m_radius(radius)
{	
}

btVector3	btSphereShape::localGetSupportingVertexWithoutMargin(const btVector3& vec)const
{
	return btVector3(0.f,0.f,0.f);
}

void	btSphereShape::batchedUnitVectorGetSupportingVertexWithoutMargin(const btVector3* vectors,btVector3* supportVerticesOut,int numVectors) const
{
	for (int i=0;i<numVectors;i++)
	{
		supportVerticesOut[i].setValue(0.f,0.f,0.f);
	}
}


btVector3	btSphereShape::localGetSupportingVertex(const btVector3& vec)const
{
	btVector3 supVertex;
	supVertex = localGetSupportingVertexWithoutMargin(vec);

	btVector3 vecnorm = vec;
	if (vecnorm .length2() < (SIMD_EPSILON*SIMD_EPSILON))
	{
		vecnorm.setValue(-1.f,-1.f,-1.f);
	} 
	vecnorm.normalize();
	supVertex+= getMargin() * vecnorm;
	return supVertex;
}


//broken due to scaling
void btSphereShape::getAabb(const btTransform& t,btVector3& aabbMin,btVector3& aabbMax) const
{
	const btVector3& center = t.getOrigin();
	btVector3 extent(getMargin(),getMargin(),getMargin());
	aabbMin = center - extent;
	aabbMax = center + extent;
}



void	btSphereShape::calculateLocalInertia(btScalar mass,btVector3& inertia)
{
	btScalar elem = 0.4f * mass * getMargin()*getMargin();
	inertia[0] = inertia[1] = inertia[2] = elem;

}
