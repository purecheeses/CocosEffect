attribute vec4 a_position;
attribute vec2 a_texCoord;
attribute vec4 a_color;

const float Eta = 0.99;
varying vec3 Refract;

varying vec4 v_fragmentColor;
varying vec2 v_texCoord;

void main()
{
    vec4 ecposition = a_position; //gl_ModelViewMatrix* gl_Vertex;
    vec3 ecposition3 = ecposition.xyz/ecposition.w;
    vec3 i = normalize(ecposition3);
    vec3 n = normalize(gl_NormalMatrix*gl_Normal);
    Refract = refract(i,n,Eta);
    Refract = vec3(gl_TextureMatrix[0] * vec4(Refract,1.0));
    gl_Position = CC_PMatrix * a_position;
    v_fragmentColor = a_color;
    v_texCoord = a_texCoord;
} 
