struct space
{
       
  space(){}      
       
  char slot[80][50];
  float slot2[80];
  bool flag[80];
  int slot_cnt;
  int slot2_cnt;
  int refid;
  int refslot;
  int id;
  float value;
  int type;
  bool status;
  int level;
} rack[800],rack2[80][800];  
          
struct graph
{
  graph()
  {        }            
       
  char eqn[200];
  char eqn_real[200];
  D3DXVECTOR2 points[8000];
  D3DXVECTOR3 color;
        
 
}curves[80];  

struct graph_data
{
 int rows;
 int columns;
 D3DXVECTOR2 points[30][8000];
 D3DXVECTOR3 color[30];
 
       
} load_data[8];          
