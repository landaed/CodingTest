#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include "../header/rectangle2D.h"

#include "../src/component.cpp"
#include <tuple>

template <typename T>
struct unorderLess
{
    bool operator () (const std::pair<T, T>& lhs, const std::pair<T, T>& rhs) const
    {
        const auto lhs_order = lhs.first < lhs.second ? lhs : std::tie(lhs.second, lhs.first);
        const auto rhs_order = rhs.first < rhs.second ? rhs : std::tie(rhs.second, rhs.first);

        return lhs_order < rhs_order;
    }
};
int main( int argc, const char* argv[] )
{
if ( argc < 2 )
{
  std::cerr << "Specify a file to run this program.\n";
  return 1;
}
std::cout << "Running program against file: " << argv[1] << "\n";
std::ifstream file( argv[1], std::ios::binary );
if ( !file.is_open() )
{
  std::cerr << "Failed to open file.\n";
  return 2;
}
unsigned int numberOfEntities = 0;
if ( !( file >> numberOfEntities ) )
{
  std::cerr << "Failed to get number of Entities from file.\n";
  return 3;
}
Entity *entities[numberOfEntities];
Rectangle2D xRects[numberOfEntities];
Rectangle2D yRects[numberOfEntities];

std::set<std::pair<int, int>, unorderLess<int>> s;

// TODO: Add a collection of Entities.
for ( unsigned int i = 0; i < numberOfEntities; ++i )
{
  float x = 0;
  float y = 0;
  float width = 0;
  float height = 0;

  if ( !( file >> x >> y >> width >> height ) )
  {
    std::cerr << "Error getting bounds on line " << i + 1 << ".\n";
    return 4;
  }
  // Not every Entity has Components.
  std::string componentTypes;
  const auto currentPos = file.tellg();
  file >> componentTypes;
  if ( !componentTypes.empty() && !std::isalpha( componentTypes.back() ) )
  {
    file.seekg( currentPos );
    componentTypes.clear();
  }
  std::map<const char, Component*> comp;
  //Entity(Rectangle2D bounds, std::set<Component> comp)
  for ( const char type : componentTypes )
  {
    switch ( type )

    {

    case 'H':
    comp['H']=new HealthComponent();
  //  std::cout << "health" << std::endl;
    // TODO: This Entity has a HealthComponent.

    break;
    case 'A':
    comp['A']=new AttackComponent();
  //  std::cout << "attack" << std::endl;
    // TODO: This Entity has an AttackComponent.

    break;
    case 'M':
    comp['M']=new MovementComponent();
  //  std::cout << "movement" << std::endl;
    // TODO: This Entity has a MovementComponent.

    break;
    default:
    std::cerr << "Unknown Component type: " << type << "\n" << std::endl;
    break;
    }

  }
  entities[i] = new Entity(Rectangle2D(vec2(x,y),vec2(width,height),i),comp);
  std::cout << std::endl << std::endl;
  // TODO: Use the above information to create an Entity with
  // a Rectangle2D bounding box and given Components.
}
file.close();

std::cout << "num of entities: " << numberOfEntities << std::endl;


const auto start = std::chrono::high_resolution_clock::now();
// TODO: Algorithm to detect number of Entity intersections.

for(int i = 0; i < (int)(numberOfEntities)-1; i++){
  for(int j = i+1; j < (int)numberOfEntities; j++){
    if(isIntersect(entities[i]->getRect(),entities[j]->getRect())){
      s.insert({i,j});
    }
  }
}

std::cout << "Amount of overlaps (X): " << s.size() << std::endl;
const auto end = std::chrono::high_resolution_clock::now();
const auto runMS =
std::chrono::duration_cast<std::chrono::milliseconds>( end - start );
std::cout << "Algorithm executed in " << runMS.count() << "ms.\n";
return 0;
}
