//windows global variables
HWND              g_hWnd       = NULL,save_or_open =NULL,about =NULL;
LPDIRECT3D9       g_pD3D       = NULL;
LPDIRECT3DDEVICE9 g_pd3dDevice = NULL;
UINT OUT_MSG;
WPARAM OUT_PARAM;
HANDLE hf;
//TEST variables


D3DXVECTOR2 TEST_vect2d[8000],axis[2];
D3DXVECTOR3 avg;
int TEST_cnt=0;
char test[30];


//function variables


LPD3DXSPRITE new_sprite;
LPD3DXLINE new_line;
fstream file,file2;
string str;
char GL_STRING[120];
LPDIRECT3DTEXTURE9 font[100],Point;
int rack_cnt =1,current_rack=0,input_activ=0;
int rack2_cnt[800],stack[20],stack_cnt =0,max_level=0,current_eqn=0,rack2_max_level[800],curve_cnt;
float GL_A,GL_B,GL_C,ans,zoom_factor=1,zoom_eye_x=683,zoom_eye_y=384,zoom_limit_r=690,zoom_limit_l=-690;
D3DXVECTOR2 calibration[90];

/*
stack[] -> stack for storing the index of racks when a bracket is encountered.
max_level -> maximum level of cascading.


*/
