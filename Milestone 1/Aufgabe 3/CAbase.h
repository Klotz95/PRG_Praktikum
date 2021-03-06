#include <stdlib.h>
#include <ctime>

class CAbase
{
public:
  CAbase()
    : Ny(10)
    , Nx(10)
    , nochanges(false)
  {
      ResetWorldSize( Nx , Ny, 1 );
  }
  CAbase( int nx, int ny )
    : Ny(ny)
    , Nx(nx)
    , nochanges(false)
  {
      ResetWorldSize( Nx , Ny, 1 );
  }

  void ResetWorldSize( int nx, int ny, bool del = 0 );

  int GetNy() { return Ny; }
  int GetNx() { return Nx; }
  int GetColor(int x, int y) { return worldColor[y*(Nx+2)+x]; }
  void SetColor( int x, int y, int c);
  void SetColorEvo( int x, int y, int c);
  int GetLife(int x, int y) { return worldLife[y*(Nx+2)+x]; }
  void SetLife( int x, int y, int l);
  void SetLifeEvo( int x, int y, int l);
  void SetAlive( int x, int y, int i );
  void SetAliveEvo( int x, int y, int i );
  int IsAlive( int x, int y ) { return world[y*(Nx+2)+x]; }
  bool IsNotChanged() { return nochanges; }
  int CellEvolutionLife( int x, int y );
  int CellEvolutionLifeColor( int x, int y );
  void WorldEvolutionLife(int mode = 0);
  void WorldEvolutionLifeColor();
  ~CAbase()
  {
  }
private:
  int Ny;
  int Nx;
  int *world;
  int *worldNew;
  int *worldColor;
  int *worldColorNew;
  int *worldLife;
  int *worldLifeNew;
  bool nochanges;
};

inline void CAbase::SetAlive( int x, int y, int i ) // Set number i into cell with coordinates x,y in current universe
{
  world[y*(Nx+2)+x] = i;
}

inline void CAbase::SetAliveEvo( int x, int y, int i ) // Set number i into cell with coordinates x,y in evolution universe
{
  worldNew[y*(Nx+2)+x] = i;
}

inline void CAbase::SetColor( int x, int y, int c) //Set color c into cell with coordinates x,y in current color universe
{
    worldColor[y*(Nx+2)+x] = c;
}

inline void CAbase::SetColorEvo( int x, int y, int c) // Set color c into cell with coordinates x,y in evolution color universe
{
    worldColorNew[y*(Nx+2)+x] = c;
}

inline void CAbase::SetLife( int x, int y, int l) //Set lifetime l into cell with coordinates x,y in current color universe
{
    worldLife[y*(Nx+2)+x] = l;
}

inline void CAbase::SetLifeEvo( int x, int y, int l) // Set lifetime l into cell with coordinates x,y in evolution color universe
{
    worldLifeNew[y*(Nx+2)+x] = l;
}

//
// Game "Life" rules:
//
// Any live cell with fewer than two live neighbours dies, as if caused by underpopulation.
// Any live cell with two or three live neighbours lives on to the next generation.
// Any live cell with more than three live neighbours dies, as if by overpopulation.
// Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
//
//
inline int CAbase::CellEvolutionLife( int x, int y ) // Classic Life. Evolution rules for every cell. Changing only cell (x, y) for every step
{
  int n_sum = 0;
  int x1(0), y1(0);
  for( int ix = -1; ix <= 1; ix++ ) {
    for( int iy = -1; iy <= 1; iy++ ) {
      if( ix == 0 && iy == 0 ) continue;
      x1 = x + ix;
      y1 = y + iy;
      if( x1 < 1 ) x1 = Nx;
      if( x1 > Nx ) x1 = 1;
      if( y1 < 1 ) y1 = Ny;
      if( y1 > Ny ) y1 = 1;
      if( IsAlive( x1, y1 ) == 1 ) n_sum++;
    }
  }
  if( IsAlive( x, y ) == 1 ) {
    if( n_sum == 2 || n_sum == 3 ) SetAliveEvo( x, y, 1 );
    else SetAliveEvo( x, y, 0 );
  }
  else {
    if( n_sum == 3 ) SetAliveEvo( x, y, 1 );
  }
  return 0;
}

//Cyclic cellular automata with von Neumann neighbourhood(northCell, westCell, eastCell, southCell).
//
//The cell can be in 12 states (Number of colors), which we will number with the numbers 0, 1, ..., 11.
//We say that the state m is next to the state k if m + 1 = k (mod n).
//A cell from the state m goes to the next state k if at least one of the neighbouring cells has the state k.
//
//
inline int CAbase::CellEvolutionLifeColor( int x, int y ) // Cyclic cellular automaton
{
  int n_sum = 0;
  int nextColor = (GetColor( x, y ) + 1) % 12;
  int x1(0), y1(0);
  for( int ix = -1; ix <= 1; ix++ ) {
      if( ix == 0 ) continue;
      x1 = x + ix;
      if( x1 < 1 ) x1 = Nx;
      if( x1 > Nx ) x1 = 1;
      if( GetColor( x1, y ) == nextColor ) n_sum++;
    }
  for( int iy = -1; iy <= 1; iy++ ) {
      if( iy == 0 ) continue;
      y1 = y + iy;
      if( y1 < 1 ) y1 = Ny;
      if( y1 > Ny ) y1 = 1;
      if( GetColor( x, y1 ) == nextColor ) n_sum++;
    }

  if( n_sum > 0 )
      SetColorEvo( x, y, nextColor );
  else
      SetColorEvo( x, y, GetColor( x, y) );

  return 0;
}


// Run evolution for every cell of universe array
// Type of evolution is determined by 'mode'
// After full evolution, new state of of universe have to be copied into current state
inline void CAbase::WorldEvolutionLife( int mode )
{
    for( int ix = 1; ix <= Nx; ix++ ) {                   // Universe evolution for every cell
        for( int iy = 1; iy <= Ny; iy++ ) {
            switch(mode){
            case 0:
                CellEvolutionLife( ix, iy );
                break;
            }
        }
    }
    nochanges = true;
      for( int ix = 1; ix <= Nx; ix++ ) {           // Copy new state to current universe
        for( int iy = 1; iy <= Ny; iy++ ) {
        if( world[iy*(Nx+2)+ix] != worldNew[iy*(Nx+2)+ix] ) nochanges = false;
        world[iy*(Nx+2)+ix] = worldNew[iy*(Nx+2)+ix];
        }
    }                                 // if nochanges == true, there are no evolution and we reached final stare of universe
}


//
// Run evolution for every cell of universe array in "Cyclic cellular automata" mode
// After full evolution, new state of of universe have to be copied into current state
//
inline void CAbase::WorldEvolutionLifeColor()
{
    for( int ix = 1; ix <= Nx; ix++ ) {             // Universe evolution for every cell
      for( int iy = 1; iy <= Ny; iy++ ) {
          CellEvolutionLifeColor( ix, iy );
      }
    }
    for( int ix = 1; ix <= Nx; ix++ ) {         // Copy new state to current universe
      for( int iy = 1; iy <= Ny; iy++ ) {
        worldColor[iy*(Nx+2)+ix] = worldColorNew[iy*(Nx+2)+ix];
      }
    }
}

//
// Creation or re-creation new current and evolution universe with default value (0 for non-border cell and -1 for border cell)
//
//
inline void CAbase::ResetWorldSize( int nx, int ny, bool del )
{
  Nx = nx;
  Ny = ny;
  if( !del ) {
    delete[] world;
    delete[] worldNew;
    // Color
    delete[] worldColor;
    delete[] worldColorNew;
    // Life
    delete[] worldLife;
    delete[] worldLifeNew;
  }
  world = new int[(Ny+2)*(Nx+2)+1];
  worldNew = new int[(Ny+2)*(Nx+2)+1];
  // Color
  worldColor = new int[(Ny+2)*(Nx+2)+1];
  worldColorNew = new int[(Ny+2)*(Nx+2)+1];
  // Life
  worldLife = new int[(Ny+2)*(Nx+2)+1];
  worldLifeNew = new int[(Ny+2)*(Nx+2)+1];
  for( int i = 0; i <= (Ny+2)*(Nx+2); i++ ) {
    if( (i < (Nx+2)) || (i >= (Ny+1)*(Nx+2)) || (i%(Nx+2) == 0) || (i%(Nx+2) == (Nx+1)) ) {
	world[i] = -1;
	worldNew[i] = -1;
    // Color
    worldColor[i] = -1;
    worldColorNew[i] = -1;
    // Life
    worldLife[i] = -1;
    worldLifeNew[i] = -1;
    }
    else {
	world[i] = 0;
	worldNew[i] = 0;
    // Color
    worldColor[i] = 0;
    worldColorNew[i] = 0;
    // Life
    worldLife[i] = 0;
    worldLifeNew[i] = 0;
    }
  }
}



