varying vec4 v_fragmentColor;
varying vec2 v_texCoord;
const float MaxEta = 3.0;
const float radius = 0.5;

void main()
{
    float r = sqrt((v_texCoord.x-0.5)*(v_texCoord.x-0.5)+(v_texCoord.y-0.5)*(v_texCoord.y-0.5));
    vec2 newTexCoord = v_texCoord;
    if (r < radius){
        float step = smoothstep(0.0,1.0,r/radius);
        float maxEta = pow(MaxEta,mod(CC_Time.w,10.0))+1.0;
        float Eta = (maxEta-step*(maxEta-1.0));
        float alpha = asin(r/2.0);
        float beta = asin(r/2.0/Eta);
        float h = 2.0*cos(alpha) -1.0 ;
        float newR = r + tan(beta-alpha)*h;
        float x = (v_texCoord.x-0.5)*(newR/r) + 0.5;
        float y = (v_texCoord.y-0.5)*(newR/r) + 0.5;
        newTexCoord = vec2(x,y);
    }
    
    vec4 Color = texture2D(CC_Texture0, newTexCoord);
//        v_fragmentColor * texture2D(CC_Texture0, vec2(Refract.xy));
    gl_FragColor = vec4(Color.rgb,Color.a*0.1);
}
