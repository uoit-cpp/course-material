# Class Exercise

*Due back before the end of the class*

## 2D Terrain Generation

I was hoping to write a C++ routine to generate 2D terrain similar to minecraft.  The program was supposed to have the following output.

~~~bash
./a.out
Coal,Rock,Mud,
Iron,
Gold,Coal,Coal,Iron,Iron,
Mud,Iron,Coal,Gold,Coal,Gold,
Gold,Iron,Rock,Rock,
Mud,Coal,Iron,Coal,
Iron,Mud,Coal,Iron,Coal,Iron,Coal,Iron,
Iron,Coal,Mud,Mud,Iron,Mud,Coal,
Rock,Gold,Coal,Rock,Mud,Coal,Mud,Gold,Rock,
Iron,Mud,Rock,Gold,Coal,Iron,Rock,Iron,
~~~

### Part 1

The code below should do it, but it seems to have a _silly_ error.  **Can you fix it?**

~~~cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class world
{
  protected:
  vector<vector<string> > _terrain;
  
  public:
  world() {}

  void gen_terrain(int xstart, int xend, int elevation) {
    vector<string> block_type;
    block_type.push_back("Coal");
    block_type.push_back("Rock");
    block_type.push_back("Mud");
    block_type.push_back("Gold");
    block_type.push_back("Iron");
    block_type.push_back("Diamond");
    int types_of_blocks = block_type.size();
                                  
    vector<string> column;
    for (int i=xstart; i<=xend; ++i) {
      //cout << "column = " << i << endl;

      int height = rand(1, elevation);
      //cout << "height = " << height << endl;
        
      for (int j = 0; j < height; ++j)
      {
        column.push_back( block_type[rand(0,types_of_blocks-1)] );
      }
      _terrain.push_back(column);
    }
  }

  void prn_terrain()
  {
    vector<vector<string> >::iterator column;
    vector<string>::iterator block;

    for (column = _terrain.begin(); column != _terrain.end(); ++column){
      for (block = (*column).begin(); block != (*column).end(); ++block) {
        cout << *block << ",";
      }
      cout << endl;
    }
  }

  private:
  static int rand(int low, int high)
  {
    double r = (double) ::rand() / RAND_MAX; // ::rand to access the global namespace
    return r * ((double)high - (double)low) + (double)low;
  }
};

int main()
{
  srand(0);

  world w;
  w.gen_terrain(1,5,4);
  w.prn_terrain();
  
  return 0;
}
~~~

### Part 2

Can you add a function that can print (and return) the locations of a particular resource?  

E.g., in the above example terrain

~~~cpp
w.prn_locations("Mud");  // This function currently doesn't exist - TODO
~~~

would print

~~~cpp
(1,3), (4,1), (6,1), (7,2), (8,3), (8,4), (8,6), (9,5), (9,7), (10,2)
~~~

and also return a _list_ containing these values.

### Submission

Submit part 1 and part 2 via blackboard.

