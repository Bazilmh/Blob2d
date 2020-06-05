/*

*/

LRESULT CALLBACK WindowProc( HWND   hWnd, UINT   msg, WPARAM wParam, LPARAM lParam );
void init( void );
void shutDown( void );
void render( void );
void TEST_IN_001();
void TEST_LOOP_001();
void TEST_IN_002();
void TEST_LOOP_002();
void M3D_vertex_indicator(D3DXVECTOR2 pos,D3DXVECTOR2 rot,float angle,LPDIRECT3DTEXTURE9 text,float r,float g,float b );
float dist3d(float x1,float y1,float z1,float x2,float y2, float z2);
void M3D_display_vertices();
void M3D_load_textures();
void M3D_display_word(char*word,int x,int y,float r,float g,float b);//for displaying text
void M3D_draw_lines(D3DXVECTOR2 vect[],int cnt,float r, float g,float b );
BOOL CALLBACK M3D_move_object(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
bool is_acceptable(char ch); 
void resolve_equation(char*str,int);
void calculate_values(int,float);
void convert_to_numeric();
int function_type(char*str,int index);
void draw_graph(int,float,float);
void alter_values();
void zoom_in();
void load_data_from_file(char*);
void display_data(int);
