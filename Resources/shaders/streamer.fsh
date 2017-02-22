varying vec4 v_fragmentColor;
varying vec2 v_texCoord;

const float a = 1.0;
const float b = 1.0;
const float c = -1.5;
const float width = 0.2;    //流光宽度
const vec4 color = vec4(1,1,1,1);
const float factor = 0.5;

void main()
{
    float c = -smoothstep(0.0,4.0,mod(CC_Time.w,4.0))*2.0;
    vec4 texColor = texture2D(CC_Texture0, v_texCoord);
    float sqrtAB = sqrt(a*a+b*b);
    float distance = abs((v_texCoord[0]*a+v_texCoord[1]*b+c)/sqrtAB);
    distance = 1.0-(1.0/width)*distance;
    distance = max(distance, 0.0);
    vec4 sample = vec4(0.0,0.0,0.0,0.0);
    sample[0] = color[0] * distance;
    sample[1] = color[1] * distance;
    sample[2] = color[2] * distance;
    sample[3] = distance;
    
    // blend additive
    float alpha = sample[3]*texColor[3];
    texColor[0] = texColor[0] + sample[0]*alpha*factor;
    texColor[1] = texColor[1] + sample[1]*alpha*factor;
    texColor[2] = texColor[2] + sample[2]*alpha*factor;
    gl_FragColor = v_fragmentColor * texColor;
}
