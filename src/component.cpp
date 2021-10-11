#include<set>
#include <map>
#include "../header/rectangle2D.h"

class Component
{
public:
virtual ~Component() = default;
// You may add to the interface.
};
// A few basic Components. Entities can have up to one of each Component type.
// Assume they will have more methods, and there will be more Components: those
// details are not important for this test.
// Add anything needed to support your implementation.
class HealthComponent : public Component
{
private:
  int m_health = 0;
public:
  HealthComponent(){
    m_health = 100;
  }
  HealthComponent(const HealthComponent &hComp){
  	m_health = hComp.m_health;
  };
};
class AttackComponent : public Component
{
private:
  int m_attackPower = 0;
public:
  AttackComponent(){
    m_attackPower = 10;
  }
};
class MovementComponent : public Component
{
private:
  int m_speed = 0;
public:
  MovementComponent(){
    m_speed = 20;
  }
};
class Entity
{
private:
  std::map<const char, Component*> components;
  Rectangle2D boundingBox;
public:
  Entity(Rectangle2D bounds, std::map<const char, Component*> comp){
    boundingBox = bounds;
    components = comp;
  }
  ~Entity(){
    for(std::map<const char, Component*>::iterator it = components.begin(); it != components.end(); ++it)
    {
      delete it->second;
    }
    components.clear();
  }
  // Copy constructor
  Entity(const Entity &entity) {
    components = entity.components;
    boundingBox = entity.boundingBox;
  }
  Rectangle2D getRect(){
    return boundingBox;
  }
  std::map<const char, Component*> getComp(){
    return components;
  }
};
