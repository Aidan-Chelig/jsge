#include "Scene.h"

Scene::Scene(){
}

Scene::~Scene(){
}

void Scene::update(){
  
}

Entity Scene::createEntity(){
  Entity entity;
  
  entities.push_back(entity);

  return entity;
}