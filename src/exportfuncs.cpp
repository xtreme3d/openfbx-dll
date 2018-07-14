#include "ofbx.h"

#define OfExport extern "C" __declspec(dllexport)

// Scene
OfExport void* fbxSceneLoad(const unsigned char* data, int size)
{
    ofbx::IScene* scene = ofbx::load(data, size);
    return (void*)scene;
}

OfExport void fbxSceneDestroy(void* sc)
{
    ofbx::IScene* scene = (ofbx::IScene*)sc;
    scene->destroy();
}

OfExport int fbxSceneGetMeshCount(void* sc)
{
    ofbx::IScene* scene = (ofbx::IScene*)sc;
    return scene->getMeshCount();
}

OfExport void* fbxSceneGetMesh(void* sc, int index)
{
    ofbx::IScene* scene = (ofbx::IScene*)sc;
    return (void*)scene->getMesh(index);
}

// Object
OfExport double fbxObjectGetLocalPosition(void* ob, int index)
{
    ofbx::Object* obj = (ofbx::Object*)ob;
    ofbx::Vec3 p = obj->getLocalTranslation();
    if (index == 0) return p.x;
    else if (index == 1) return p.y;
    else return p.z;
}

OfExport double fbxObjectGetLocalRotation(void* ob, int index)
{
    ofbx::Object* obj = (ofbx::Object*)ob;
    ofbx::Vec3 p = obj->getLocalRotation();
    if (index == 0) return p.x;
    else if (index == 1) return p.y;
    else return p.z;
}

OfExport double fbxObjectGetLocalScaling(void* ob, int index)
{
    ofbx::Object* obj = (ofbx::Object*)ob;
    ofbx::Vec3 p = obj->getLocalScaling();
    if (index == 0) return p.x;
    else if (index == 1) return p.y;
    else return p.z;
}

OfExport ofbx::Matrix fbxObjectGetGlobalTransform(void* ob)
{
    ofbx::Object* obj = (ofbx::Object*)ob;
    return obj->getGlobalTransform();
}

// Mesh
OfExport int fbxMeshGetVertexCount(void* me)
{
    ofbx::Mesh* mesh = (ofbx::Mesh*)me;
    return mesh->getGeometry()->getVertexCount();
}

OfExport double* fbxMeshGetVertices(void* me)
{
    ofbx::Mesh* mesh = (ofbx::Mesh*)me;
    return (double*)mesh->getGeometry()->getVertices();
}

/*
OfExport float meshGetVertex(void* me, int index, int coord)
{
    ofbx::Mesh* mesh = (ofbx::Mesh*)me;
    const ofbx::Vec3* v = &mesh->getGeometry()->getVertices()[index];
    if (coord == 0) return v->x;
    else if (coord == 1) return v->y;
    else if (coord == 2) return v->z;
}
*/

OfExport double* fbxMeshGetNormals(void* me)
{
    ofbx::Mesh* mesh = (ofbx::Mesh*)me;
    return (double*)mesh->getGeometry()->getNormals();
}

OfExport double* fbxMeshGetUVs(void* me)
{
    ofbx::Mesh* mesh = (ofbx::Mesh*)me;
    return (double*)mesh->getGeometry()->getUVs();
}

OfExport double* fbxMeshGetColors(void* me)
{
    ofbx::Mesh* mesh = (ofbx::Mesh*)me;
    return (double*)mesh->getGeometry()->getColors();
}

OfExport double* fbxMeshGetTangents(void* me)
{
    ofbx::Mesh* mesh = (ofbx::Mesh*)me;
    return (double*)mesh->getGeometry()->getTangents();
}


