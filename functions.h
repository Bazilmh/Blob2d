
//------------------------------------------------------------------------------
LRESULT CALLBACK WindowProc( HWND   hWnd, 
							 UINT   msg, 
							 WPARAM wParam, 
							 LPARAM lParam )
{
         
    OUT_MSG = msg; 
    OUT_PARAM = wParam;    
         
         
    switch( msg )
	{
        case WM_KEYDOWN:
		{
			switch( wParam )
			{
				case VK_ESCAPE:
					PostQuitMessage(0);
					break;
				
					
			}
		}
        break;
        
        case WM_LBUTTONDOWN:
             {
             
             
             
             
              }
              break;
              
              
        case WM_RBUTTONDOWN:
             { 
            
        
            
                                                                      
              }
              break;
              
      
               
          
       case WM_COMMAND:
             {
              switch(LOWORD(wParam))
              {
                case 2003:
                if(about == NULL)    
                about = CreateDialog(GetModuleHandle(NULL),MAKEINTRESOURCE(M3D_DIA_004),g_hWnd, M3D_move_object);     
                break;
                
                case 2002:
                if(save_or_open == NULL)     
                save_or_open = CreateDialog(GetModuleHandle(NULL),MAKEINTRESOURCE(M3D_DIA_005),g_hWnd, M3D_move_object);                         
                break;                              
              }
            }
        break;
		case WM_CLOSE:
		{
           	//MessageBox(g_hWnd,"save changes to file?","Confirm?",MB_YESNO);  
			PostQuitMessage(0);
		
		}
		//break;
        case WM_DESTROY:
		{
            PostQuitMessage(0);
		}
        break;

		default:
		{
			return DefWindowProc( hWnd, msg, wParam, lParam );
		}
		break;
	}

	return 0;
}
//==============================================================================





//------------------------------------------------------------------------------
void init( void )
{
    g_pD3D = Direct3DCreate9( D3D_SDK_VERSION );

	if( g_pD3D == NULL )
	{
		// TO DO: Respond to failure of Direct3DCreate8
		return;
	}

    D3DDISPLAYMODE d3ddm;

    if( FAILED( g_pD3D->GetAdapterDisplayMode( D3DADAPTER_DEFAULT, &d3ddm ) ) )
	{
		// TO DO: Respond to failure of GetAdapterDisplayMode
		return;
	}

	HRESULT hr;

	if( FAILED( hr = g_pD3D->CheckDeviceFormat( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, 
												d3ddm.Format, D3DUSAGE_DEPTHSTENCIL,
												D3DRTYPE_SURFACE, D3DFMT_D16 ) ) )
	{
		if( hr == D3DERR_NOTAVAILABLE )
			// POTENTIAL PROBLEM: We need at least a 16-bit z-buffer!
			return;
	}

	//
	// Do we support hardware vertex processing? if so, use it. 
	// If not, downgrade to software.
	//

	D3DCAPS9 d3dCaps;

	if( FAILED( g_pD3D->GetDeviceCaps( D3DADAPTER_DEFAULT, 
		                               D3DDEVTYPE_HAL, &d3dCaps ) ) )
	{
		// TO DO: Respond to failure of GetDeviceCaps
		return;
	}

	DWORD dwBehaviorFlags = 0;

	if( d3dCaps.VertexProcessingCaps != 0 )
		dwBehaviorFlags |= D3DCREATE_HARDWARE_VERTEXPROCESSING;
	else
		dwBehaviorFlags |= D3DCREATE_SOFTWARE_VERTEXPROCESSING;

	//
	// Everything checks out - create a simple, windowed device.
	//

	D3DPRESENT_PARAMETERS d3dpp;
	memset(&d3dpp, 0, sizeof(d3dpp));

    d3dpp.BackBufferFormat       = d3ddm.Format;
	d3dpp.SwapEffect             = D3DSWAPEFFECT_DISCARD;
	d3dpp.Windowed               = 1;
    d3dpp.EnableAutoDepthStencil = TRUE;
    d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
    d3dpp.PresentationInterval   = D3DPRESENT_INTERVAL_IMMEDIATE;

    if( FAILED( g_pD3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, g_hWnd,
                                      dwBehaviorFlags, &d3dpp, &g_pd3dDevice ) ) )
	{
		// TO DO: Respond to failure of CreateDevice
		return;
	}
	
	

	



M3D_load_textures();


TEST_IN_002();


               
	
}
//==============================================================================


//------------------------------------------------------------------------------
void shutDown( void )
{
    if( g_pd3dDevice != NULL )
        g_pd3dDevice->Release();

    if( g_pD3D != NULL )
        g_pD3D->Release();
}
//==============================================================================


//------------------------------------------------------------------------------
//----------------------MAIN RENDERING FUNCTION---------------------------------
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void render( void )
{
 
     
g_pd3dDevice->Clear( 0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,D3DCOLOR_COLORVALUE(0.0f,0.0f,0.0f,1.0f), 1.0f, 0 );

D3DXVECTOR2 vect;                         
                     
TEST_LOOP_001();
TEST_LOOP_002();

                         
g_pd3dDevice->Present( NULL, NULL, NULL, NULL );
}

//==============================================================================

//------------------------------------------------------------------------------
void TEST_LOOP_001()
{


ShowWindow(save_or_open, SW_SHOW);
ShowWindow(about, SW_SHOW);



     
}
//==============================================================================     

//------------------------------------------------------------------------------
void TEST_LOOP_002()
{

     
//M3D_vertex_indicator(TEST_vect2d[i],D3DXVECTOR2(0,0),0,Point,1,0,0);




axis[0] = D3DXVECTOR2(0,zoom_eye_y);
axis[1] = D3DXVECTOR2(1366,zoom_eye_y);
M3D_draw_lines(axis,2,0,1,0);
axis[0] = D3DXVECTOR2(zoom_eye_x,0);
axis[1] = D3DXVECTOR2(zoom_eye_x,768);
M3D_draw_lines(axis,2,0,1,0);

     

zoom_in();       

alter_values();


for(int i=0;i<curve_cnt;i++)
{
draw_graph(i,zoom_limit_l/zoom_factor,zoom_limit_r/zoom_factor);
M3D_draw_lines(curves[i].points,1380,curves[i].color.x,curves[i].color.y,curves[i].color.z);

}

//M3D_display_word(itoa(TEST_cnt,GL_STRING,10),500,500,0,1,0);
display_data(0);

/*M3D_display_word(itoa(0,GL_STRING,10),zoom_eye_x,zoom_eye_y,1,0,0);

for(int i=0;i<800;i+=int(50/zoom_factor) )
{
if( (zoom_eye_x+(i*zoom_factor)) < 1366 )
{
M3D_display_word(itoa(i,GL_STRING,10),zoom_eye_x+(i*zoom_factor),zoom_eye_y,1,0,0);

}
}*/

/*

for(int i=0;i<20;i++)
{
M3D_display_word(itoa(curves[0].points[i].y*100,GL_STRING,10),i*70,520,0,1,1);
   

}

for(int i=0;i<20;i++)
{
        
for(int j=0;j<20;j++)
{        

//M3D_display_word(itoa(rack2[i][j].slot_cnt,GL_STRING,10),i*60,415,0,1,0); 
//M3D_display_word(itoa(rack2[i][j].level,GL_STRING,10),i*60,445,0,1,0);
//M3D_display_word(itoa(rack2[i][j].type,GL_STRING,10),i*60,475,0,1,0);
M3D_display_word(itoa(rack2[0][i].flag[j],GL_STRING,10),i*60,j*20,1,0,0);
M3D_display_word(itoa(rack2[0][i].slot2[j]*1000,GL_STRING,10),i*60+20,j*20,0,1,0);


}

M3D_display_word(itoa(rack2[0][i].type,GL_STRING,10),i*60,400,1,0,0);
M3D_display_word(itoa(rack2[0][i].value*1000,GL_STRING,10),i*60,420,1,1,0);
M3D_display_word(itoa(TEST_vect2d[i].x*1000,GL_STRING,10),i*60,540,1,0,1);

}

M3D_display_word(itoa(rack_cnt,GL_STRING,10),0,480,1,0,0); 
M3D_display_word(itoa(stack_cnt,GL_STRING,10),0,500,1,0,0);


*/

/*
for(int i=0;i<20;i++)
{
  for(int j=0;j<20;j++)
  {
 
 M3D_display_word(itoa(rack2[0][i].flag[j],GL_STRING,10),i*60,j*15,1,0,0); 
 M3D_display_word(itoa(rack2[0][i].slot2[j]*1000,GL_STRING,10),(i*60)+10,j*15,0,1,0);         
  
                
  }
}

*/
}
//------------------------------------------------------------------------------
void TEST_IN_002()
{
     D3DXCreateSprite(g_pd3dDevice,&new_sprite);
     D3DXCreateLine(g_pd3dDevice,&new_line);
     




     
int cnt =0;    
         
   for(float i=1;i>=0.1;i-=0.3)
   {
   for(float j=1;j>=0.1;j-=0.3)
   {
   for(float k=1;k>=0.1;k-=0.3)
   {      
   
   curves[cnt].color.x = i;
   curves[cnt].color.y = j;
   curves[cnt].color.z = k;
   
cnt++;   
}
}
}

load_data_from_file("data23.txt");
   
}     
//==============================================================================

//------------------------------------------------------------------------------
void M3D_vertex_indicator(D3DXVECTOR2 pos,D3DXVECTOR2 rot,float angle,LPDIRECT3DTEXTURE9 text,float r,float g,float b )
{
g_pd3dDevice->BeginScene();
    {
      new_sprite->Begin();
      {
       
        
        new_sprite->Draw(text,NULL,NULL,&rot,angle,&pos,D3DCOLOR_COLORVALUE(r,g,b,1.0));
                                            
      }
      new_sprite->End();
     }
    g_pd3dDevice->EndScene();


     
}
//==============================================================================     

//------------------------------------------------------------------------------




//------------------------------------------------------------------------------
float dist3d(float x1,float y1,float z1,float x2,float y2, float z2)               
{
       
 return sqrt( ((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)) + ((z2-z1)*(z2-z1)) );


}
//==============================================================================

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void M3D_load_textures()
{
     
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/bopen.bmp",&font[40]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/bclose.bmp",&font[41]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/mult.bmp",&font[42]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/plus.bmp",&font[43]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/minus.bmp",&font[45]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/dot.bmp",&font[46]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/divide.bmp",&font[47]);
     
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/a.tga",&font[65]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/b.tga",&font[66]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/c.tga",&font[67]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/d.tga",&font[68]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/e.tga",&font[69]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/f.tga",&font[70]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/g.tga",&font[71]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/h.tga",&font[72]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/i.tga",&font[73]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/j.tga",&font[74]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/k.tga",&font[75]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/l.tga",&font[76]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/m.tga",&font[77]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/n.tga",&font[78]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/o.tga",&font[79]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/p.tga",&font[80]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/q.tga",&font[81]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/r.tga",&font[82]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/s.tga",&font[83]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/t.tga",&font[84]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/u.tga",&font[85]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/v.tga",&font[86]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/w.tga",&font[87]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/x.tga",&font[88]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/y.tga",&font[89]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/z.tga",&font[90]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/xs.bmp",&font[int('x')]);


D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/zeros.tga",&font[48]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/ones.tga",&font[49]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/twos.tga",&font[50]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/threes.tga",&font[51]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/fours.tga",&font[52]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/fives.tga",&font[53]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/sixs.tga",&font[54]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/sevens.tga",&font[55]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/eights.tga",&font[56]);
D3DXCreateTextureFromFile(g_pd3dDevice, "images/font/nines.tga",&font[57]);

D3DXCreateTextureFromFile(g_pd3dDevice, "images/point.bmp",&Point);



     
     
}
//==============================================================================

//------------------------------------------------------------------------------
void M3D_display_word(char*word,int x,int y,float r,float g,float b)
{
D3DXVECTOR2 rot(0,0),pos;

pos.x = x;
pos.y = y;
for(int i=0;i<strlen(word);i++)
{
        
M3D_vertex_indicator( pos, rot,0,font[word[i]],r,g,b );
     
pos.x+=10;
}
                        
}
//==============================================================================



//------------------------------------------------------------------------------
void M3D_draw_lines(D3DXVECTOR2 vect[],int cnt,float r, float g,float b )
{
g_pd3dDevice->BeginScene();
{
 new_line->Begin();
 {
 
 new_line->Draw(vect,cnt,D3DCOLOR_COLORVALUE(r,g,b,1.0));                  
                   
 
 }
 new_line->End();
}
g_pd3dDevice->EndScene();
 
     
}
//==============================================================================
     
//------------------------------------------------------------------------------
BOOL CALLBACK M3D_move_object(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
     
float temp,temp2,temp3;
     
switch(Message)
{
case WM_COMMAND:
switch(LOWORD(wParam))
{             
case IDCANCEL:    
DestroyWindow(save_or_open);
save_or_open = NULL;
break;

case 1053:
curve_cnt++;
zoom_limit_r=690;zoom_limit_l=-690;
zoom_eye_x=683;zoom_eye_y=384;
temp = zoom_factor;
zoom_factor =1;
GetDlgItemText(save_or_open,1050,curves[current_eqn].eqn,120);
GetDlgItemText(save_or_open,1050,curves[current_eqn].eqn_real,120);
resolve_equation(curves[current_eqn].eqn,current_eqn);
SetDlgItemText(save_or_open,1056,curves[current_eqn].eqn);
zoom_factor =temp;
break;

case 1052:
current_eqn--; 
SetDlgItemText(save_or_open,1056,curves[current_eqn].eqn); 
break;
     
case 1055:
current_eqn++; 
SetDlgItemText(save_or_open,1056,curves[current_eqn].eqn); 
break;     

case 1049:
DestroyWindow(about);
about = NULL;
break;

  
       

}
default:                  
return FALSE;

}


return TRUE;
}
//==============================================================================

//------------------------------------------------------------------------------
bool is_acceptable(char ch)
{
     
if( (int(ch)>=65&&int(ch)<=90) || (int(ch)>=48&&int(ch)<=57) || (int(ch)>=40&&int(ch)<=43) || (int(ch)== 45) || (int(ch)==47) )     
return 1;
else
return 0;
     
}
//==============================================================================      

//------------------------------------------------------------------------------
void resolve_equation(char*str,int index)
{

for(int i=0;i<200;i++)
{
 rack[i].slot_cnt =0;
 rack[i].slot2_cnt=0;  
 /*for(int j=0;j<200;j++)
 {rack2[i][j].slot_cnt =0;
 rack2[i][j].slot2_cnt =0;}*/
  
}



rack_cnt =1,current_rack=0,max_level=0,stack_cnt=0;
for(int i=0;i<strlen(str);i++)
{

if(str[i] == '(')
{
rack[current_rack].slot[rack[current_rack].slot_cnt][0] = 'B';        
rack[current_rack].slot_cnt++;
stack[stack_cnt] = current_rack;
stack_cnt++;                         
rack[rack_cnt].status = 1;
rack[rack_cnt].type = function_type(str,i);
rack[rack_cnt].refid = current_rack;
rack[rack_cnt].refslot = (rack[current_rack].slot_cnt-1);
rack[rack_cnt].level = stack_cnt;
if(stack_cnt > max_level)
max_level = stack_cnt;
current_rack = rack_cnt;
rack_cnt++;

}
else
if(str[i] == ')')
{
stack_cnt--;
current_rack = stack[stack_cnt];          


}
else
if( (str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/') || (str[i] == 'x') || (str[i] == 'e')|| (str[i] == '^') || (str[i] == 'T')|| (str[i] == 'X')|| (str[i] == 'Y')|| (str[i] == 'Z'))
{rack[current_rack].slot[rack[current_rack].slot_cnt][0] = str[i];
rack[current_rack].slot_cnt++;}
else
if( (int(str[i]) >= 48) && (int(str[i]) <= 57) )
{
    
int cnt=0;

again:    
rack[current_rack].slot[rack[current_rack].slot_cnt][cnt] = str[i]; 



if( ((int(str[i+1]) >= 48) && (int(str[i+1]) <= 57)) || (int(str[i+1]) == 46))
{ i++;cnt++;goto again;}
else
rack[current_rack].slot_cnt++;
}


} 


convert_to_numeric();


for(int i=0;i<rack_cnt;i++)
rack2[current_eqn][i] = rack[i];

rack2_cnt[current_eqn] = rack_cnt;
rack2_max_level[current_eqn] = max_level;



  
}
//==============================================================================     

//------------------------------------------------------------------------------
void calculate_values(int index,float x)
{


for(int i=0;i<rack[index].slot2_cnt;i++)
{
 
 if(rack[index].slot2[i] == 6 && rack[index].flag[i] == 0)
 {rack[index].slot2[i] = x; rack[index].flag[i] = 1;}
 else
 if(rack[index].slot2[i] == 7 && rack[index].flag[i] == 0)
 {rack[index].slot2[i] = EXP; rack[index].flag[i] = 1;}
 else
 if(rack[index].slot2[i] == 9 && rack[index].flag[i] == 0)
 {rack[index].slot2[i] = (timeGetTime()%10000)*0.1; rack[index].flag[i] = 1;}
 else
 if(rack[index].slot2[i] == 10 && rack[index].flag[i] == 0)
 {rack[index].slot2[i] = GL_A; rack[index].flag[i] = 1;}
 else
 if(rack[index].slot2[i] == 11 && rack[index].flag[i] == 0)
 {rack[index].slot2[i] = GL_B; rack[index].flag[i] = 1;}
 else
 if(rack[index].slot2[i] == 12 && rack[index].flag[i] == 0)
 {rack[index].slot2[i] = GL_C; rack[index].flag[i] = 1;}
 
        
}


for(int i=0;i<rack[index].slot2_cnt;i++)
{    
if( rack[index].slot2[i] == 8 && rack[index].flag[i] == 0)
{

rack[index].slot2[i-1] = pow(rack[index].slot2[i-1],rack[index].slot2[i+1]);
rack[index].flag[i-1] = 1;

for(int j=i;j<rack[index].slot2_cnt;j++)
{rack[index].slot2[j] = rack[index].slot2[j+2];                
 rack[index].flag[j] = rack[index].flag[j+2];
}
rack[index].slot2_cnt-=2;
i-=2;

}
 
     
}



for(int i=0;i<rack[index].slot2_cnt;i++)
{    
if( rack[index].slot2[i] == 1 && rack[index].flag[i] == 0)
{

rack[index].slot2[i-1] = rack[index].slot2[i-1]/rack[index].slot2[i+1];
rack[index].flag[i-1] = 1;

for(int j=i;j<rack[index].slot2_cnt;j++)
{rack[index].slot2[j] = rack[index].slot2[j+2];                
 rack[index].flag[j] = rack[index].flag[j+2];
}
rack[index].slot2_cnt-=2;
i-=2;

}
 
     
}



for(int i=0;i<rack[index].slot2_cnt;i++)
{    
if( rack[index].slot2[i] == 2 && rack[index].flag[i] == 0)
{

rack[index].slot2[i-1] = rack[index].slot2[i-1]*rack[index].slot2[i+1];
rack[index].flag[i-1] = 1;

for(int j=i;j<rack[index].slot2_cnt;j++)
{rack[index].slot2[j] = rack[index].slot2[j+2];                
 rack[index].flag[j] = rack[index].flag[j+2];
}
rack[index].slot2_cnt-=2;
i-=2;

}
 
     
}





for(int i=0;i<rack[index].slot2_cnt;i++)
{
  if(rack[index].slot2[i] == 3 && rack[index].flag[i] == 0)
  {
    if(rack[index].slot2[i+1] == 3 && rack[index].flag[i+1] == 0) 
    {
      rack[index].slot2[i] = 3;
      rack[index].flag[i] = 0;
      
    for(int j = (i+1);j<rack[index].slot2_cnt;j++)
    {rack[index].slot2[j] = rack[index].slot2[j+1];
     rack[index].flag[j] = rack[index].flag[j+1];
    }
     rack[index].slot2_cnt--;                                        
                            
     }                     
  
   if(rack[index].slot2[i+1] == 4 && rack[index].flag[i+1] == 0) 
    {
      rack[index].slot2[i] = 4;
      rack[index].flag[i] = 0;
      
    for(int j = (i+1);j<rack[index].slot2_cnt;j++)
    {rack[index].slot2[j] = rack[index].slot2[j+1];
     rack[index].flag[j] = rack[index].flag[j+1];
    }
     rack[index].slot2_cnt--;                                        
                            
     }  
  
  
  }
  
  
  
   if(rack[index].slot2[i] == 4 && rack[index].flag[i] == 0)
  {
    if(rack[index].slot2[i+1] == 3 && rack[index].flag[i+1] == 0) 
    {
      rack[index].slot2[i] = 4;
      rack[index].flag[i] = 0;
      
    for(int j = (i+1);j<rack[index].slot2_cnt;j++)
    {rack[index].slot2[j] = rack[index].slot2[j+1];
     rack[index].flag[j] = rack[index].flag[j+1];
    }
     rack[index].slot2_cnt--;                                        
                            
     }                     
  
   if(rack[index].slot2[i+1] == 4 && rack[index].flag[i+1] == 0) 
    {
      rack[index].slot2[i] = 3;
      rack[index].flag[i] = 0;
      
    for(int j = (i+1);j<rack[index].slot2_cnt;j++)
    {rack[index].slot2[j] = rack[index].slot2[j+1];
     rack[index].flag[j] = rack[index].flag[j+1];
    }
     rack[index].slot2_cnt--;                                        
                            
     }  
  
  
  }
  
        


}

if(rack[index].flag[0] != 0)
{
for(int i=(rack[index].slot2_cnt-1);i>=0;i--)
{rack[index].slot2[i+1] = rack[index].slot2[i];
rack[index].flag[i+1] = rack[index].flag[i];
}
rack[index].slot2_cnt++;
rack[index].slot2[0] = 3;
rack[index].flag[0] = 0;
}

ans = 0;
for(int i=0;i<rack[index].slot2_cnt;i++)
{

if(rack[index].slot2[i] == 3 && rack[index].flag[i] == 0)
ans+=rack[index].slot2[i+1];
else
if(rack[index].slot2[i] == 4 && rack[index].flag[i] == 0)
ans-=rack[index].slot2[i+1];



}




//ans = rack[index].slot2[0];

if(rack[index].type == 1)
rack[index].value= sinh(ans);
else
if(rack[index].type == 2)
rack[index].value = cosh(ans);
else
if(rack[index].type == 3)
rack[index].value = tanh(ans);
else
if(rack[index].type == 4)
rack[index].value = asin(ans);
else
if(rack[index].type == 5)
rack[index].value = acos(ans);
else
if(rack[index].type == 6)
rack[index].value = atan(ans);
else
if(rack[index].type == 7)
rack[index].value = sin(ans);
else
if(rack[index].type == 8)
rack[index].value = cos(ans);
else
if(rack[index].type == 9)
rack[index].value = tan(ans);
else
if(rack[index].type == 10)
rack[index].value = log(ans);
else
if(rack[index].type == 0)
rack[index].value = ans;





if(index != 0)
{rack[rack[index].refid].slot2[rack[index].refslot] = rack[index].value;
rack[rack[index].refid].flag[rack[index].refslot] = 1;
}
 //TEST_vect2d[TEST_cnt].x = x;
 //TEST_cnt++;
     
}
//==============================================================================     

//------------------------------------------------------------------------------
void convert_to_numeric()
{
for(int i=0;i<rack_cnt;i++)
{

rack[i].slot2_cnt = rack[i].slot_cnt;

for(int j=0;j<rack[i].slot2_cnt;j++)
{
        
if(rack[i].slot[j][0] == '/')
{ rack[i].slot2[j] = 1; rack[i].flag[j] = 0;}              
else
if(rack[i].slot[j][0] == '*')
{ rack[i].slot2[j] = 2; rack[i].flag[j] = 0;}        
else        
if(rack[i].slot[j][0] == '+')
{ rack[i].slot2[j] = 3; rack[i].flag[j] = 0;}              
else
if(rack[i].slot[j][0] == '-')
{ rack[i].slot2[j] = 4; rack[i].flag[j] = 0;}
else
if(rack[i].slot[j][0] == 'B')
{ rack[i].slot2[j] = 5; rack[i].flag[j] = 0;}          
else
if(rack[i].slot[j][0] == 'x')
{ rack[i].slot2[j] = 6; rack[i].flag[j] = 0;}
else
if(rack[i].slot[j][0] == 'e')
{ rack[i].slot2[j] = 7; rack[i].flag[j] = 0;}          
else
if(rack[i].slot[j][0] == '^')
{ rack[i].slot2[j] = 8; rack[i].flag[j] = 0;}
else
if(rack[i].slot[j][0] == 'T')
{ rack[i].slot2[j] = 9; rack[i].flag[j] = 0;}
else
if(rack[i].slot[j][0] == 'X')
{ rack[i].slot2[j] = 10; rack[i].flag[j] = 0;}          
else
if(rack[i].slot[j][0] == 'Y')
{ rack[i].slot2[j] = 11; rack[i].flag[j] = 0;}
else
if(rack[i].slot[j][0] == 'Z')
{ rack[i].slot2[j] = 12; rack[i].flag[j] = 0;}
else
{rack[i].slot2[j] = atof(rack[i].slot[j]); rack[i].flag[j] = 1;}

        
}        


}     
     
}
//==============================================================================     

//------------------------------------------------------------------------------
int function_type(char*strn,int index)
{
char func[5];
int type=0;
M3D_display_word(func,500,600,0,1,0);     

for(int i=0;i<3;i++)
func[i] = strn[(index-3)+i]; 
func[3] ='\0';

if( strcmp(func,"inh") == 0)
type = 1;
else
if( strcmp(func,"osh") == 0)
type = 2;
else
if( strcmp(func,"anh") == 0)
type = 3;
else
if( strcmp(func,"ini") == 0)
type = 4;
else
if( strcmp(func,"osi") == 0)
type = 5;
else
if( strcmp(func,"ani") == 0)
type = 6;
else
if( strcmp(func,"sin") == 0)
type = 7;
else
if( strcmp(func,"cos") == 0)
type = 8;
else
if( strcmp(func,"tan") == 0)
type = 9;
else
if( strcmp(func,"log") == 0)
type = 10;
else
type = 0;


//M3D_display_word(itoa(type,GL_STRING,10),500,615,0,1,0);

return type;

     
     
     
}
//==============================================================================     

//------------------------------------------------------------------------------
void draw_graph(int m,float a, float b)
{

float k=0;int l=0;     
for( k = a,l=0;k<b;k+=((b-a)/1380),l++)
{

for(int i=0;i<rack2_cnt[m];i++)
rack[i] = rack2[m][i];

rack_cnt = rack2_cnt[m];  
max_level = rack2_max_level[m];   
 
        
for(int i=max_level;i>=0;i--)
{  
for(int j=0;j<rack_cnt;j++)
{  
if(rack[j].level == i )
{ calculate_values(j,k);  }   
        
}
}


//float r, theta,x,y;

//theta = k;
//r = rack[0].value;

//x = r*cos(theta);
//y = r*sin(theta);


curves[m].points[l] = D3DXVECTOR2( ((k*zoom_factor)+zoom_eye_x),((-rack[0].value*zoom_factor)+zoom_eye_y) );  

}
     
}
//==============================================================================

//------------------------------------------------------------------------------
void alter_values()
{
if( ::GetAsyncKeyState('Q') & 0x8000f )
GL_A+=0.1;
if( ::GetAsyncKeyState('A') & 0x8000f )
GL_A-=0.1;
if( ::GetAsyncKeyState('W') & 0x8000f )
GL_B+=0.1;
if( ::GetAsyncKeyState('S') & 0x8000f )
GL_B-=0.1;
if( ::GetAsyncKeyState('E') & 0x8000f )
GL_C+=0.1;
if( ::GetAsyncKeyState('D') & 0x8000f )
GL_C-=0.1;



}
//==============================================================================

//------------------------------------------------------------------------------
void zoom_in()
{
if( ::GetAsyncKeyState('P') & 0x8000f )
zoom_factor+=0.1;
if( ::GetAsyncKeyState('M') & 0x8000f )
zoom_factor-=0.1;    
if( ::GetAsyncKeyState('K') & 0x8000f )
{zoom_eye_y-=1;}
if( ::GetAsyncKeyState('I') & 0x8000f )
{zoom_eye_y+=1;}
if( ::GetAsyncKeyState('L') & 0x8000f )
{zoom_eye_x-=1;zoom_limit_r+=1; zoom_limit_l+=1;}
if( ::GetAsyncKeyState('J') & 0x8000f )
{zoom_eye_x+=1;zoom_limit_r-=1; zoom_limit_l-=1;}

   
 
//M3D_display_word(itoa(int(zoom_limit_r),GL_STRING,10),500,615,0,1,0);     
//M3D_display_word(itoa(int(zoom_limit_l),GL_STRING,10),500,630,0,1,0);    
}               
//==============================================================================

//------------------------------------------------------------------------------
void load_data_from_file(char*strn)
{ 
 file.open("wrt.txt",ios::in);
 file>>load_data[0].rows>>load_data[0].columns;
 
 for(int i=0;i<load_data[0].columns;i++)
{
 for(int j=0;j<load_data[0].rows;j++)
{ 
   file>>load_data[0].points[j][i].x>>load_data[0].points[j][i].y;
   load_data[0].points[j][i].y = 384-load_data[0].points[j][i].y;   
     
}
}

 file.close();
 
  
 
     
}     
//==============================================================================

//------------------------------------------------------------------------------
void display_data(int index)
{
//for(int j=0;j<130;j++)
//{
for(int i=0;i<(load_data[index].rows/2);i++)
{
M3D_draw_lines(load_data[index].points[i],75,curves[i].color.x,curves[i].color.y,curves[i].color.z);
 //M3D_vertex_indicator(load_data[index].points[i][j],D3DXVECTOR2(0,0),0,Point,curves[i].color.x,curves[i].color.y,curves[i].color.z);
}
//}

}
//==============================================================================


