varying vec4 v_fragmentColor;
varying vec2 v_texCoord;
uniform float beginTime;
const float lastTime = 0.2;
void main()
{
    vec4 v_orColor = v_fragmentColor * texture2D(CC_Texture0, v_texCoord);
    if (CC_Time.y - beginTime < lastTime) {
        v_orColor *= (1.0+ (CC_Time.y - beginTime)/lastTime*3.0);
    }
    else if (CC_Time.y - beginTime < lastTime *2.0){
        v_orColor *= (1.0+ (lastTime*2.0-CC_Time.y + beginTime)/lastTime*3.0);
    }
//    float gray = dot(v_orColor.rgb, vec3(0.299, 0.587, 0.114));
    gl_FragColor = v_orColor;
}
