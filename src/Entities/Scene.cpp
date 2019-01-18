#include "Scene.h"

Scene::Scene(){
  systemManager = new SystemManager(entityManager);
}

Scene::~Scene(){
}

void Scene::update(){
  systemManager->update();
}