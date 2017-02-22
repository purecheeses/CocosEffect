varying vec4 v_fragmentColor;
varying vec2 v_texCoord;

float p_offset[9];
float p_weight[9];
const float pixel_size = 1.0/100.0;     //glsl没法的到像素距离，因为他不care，只关心归一化后结果，所以应该外部传入texture的size，这里我偷懒直接写个数了

//p_offset = float p_weight[9];
void main()
{
    p_offset[0] = -4.0;p_offset[1] = -3.0;p_offset[2] = -2.0;p_offset[3] = -1.0;p_offset[4] = -0.0;
    p_offset[5] = 1.0;p_offset[6] = 2.0;p_offset[7] = 3.0;p_offset[8] = 4.0;
    p_weight[0] = 0.05;p_weight[1] = 0.09;p_weight[2] = 0.12;p_weight[3] = 0.15;p_weight[4] = 0.16;p_weight[5] = 0.15;p_weight[6] = 0.12;p_weight[7] = 0.09;p_weight[8] = 0.05;
    
    vec4 color = vec4(0,0,0,0);
    for (int i = 0; i<9; i++) {
        color += texture2D(CC_Texture0,v_texCoord - vec2(p_offset[i]*pixel_size,0))*p_weight[i];
    }
    for (int i = 0; i<9; i++) {
        color += texture2D(CC_Texture0,v_texCoord - vec2(0,p_offset[i]*pixel_size))*p_weight[i];
    }
    gl_FragColor = color/2.0;
}
