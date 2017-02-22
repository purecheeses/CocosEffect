varying vec4 v_fragmentColor;
varying vec2 v_texCoord;
varying vec3 Refract;

void main()
{
    vec4 Color =
//        v_fragmentColor *texture2D(CC_Texture0, v_texCoord);
        v_fragmentColor * texture2D(CC_Texture0, vec2(Refract.xy));
    gl_FragColor = vec4(Color);
}
