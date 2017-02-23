varying vec4 v_fragmentColor;
varying vec2 v_texCoord;

const float pixel_size = 1.0/155.0;
//Sobel边界探测法
const float frontiere = 0.001;
float gray(vec4 rgba){
    return dot(rgba.rgb, vec3(0.299, 0.587, 0.114));
}

void main()
{
    vec2 textureCoordinate = v_texCoord;
    vec2 leftTextureCoordinate = v_texCoord + vec2(-pixel_size,0);
    vec2 rightTextureCoordinate= v_texCoord + vec2(pixel_size,0);;
    
    vec2 topTextureCoordinate = v_texCoord + vec2(0,pixel_size);
    vec2 topLeftTextureCoordinate= v_texCoord + vec2(-pixel_size,pixel_size);;
    vec2 topRightTextureCoordinate=v_texCoord + vec2(pixel_size,pixel_size);;
    
    vec2 bottomTextureCoordinate = v_texCoord + vec2(0,-pixel_size);;
    vec2 bottomLeftTextureCoordinate = v_texCoord + vec2(-pixel_size,-pixel_size);;
    vec2 bottomRightTextureCoordinate = v_texCoord + vec2(pixel_size,-pixel_size);;
    
    float bottomLeftIntensity = gray(texture2D(CC_Texture0, bottomLeftTextureCoordinate));
    float topRightIntensity = gray(texture2D(CC_Texture0, topRightTextureCoordinate));
    float topLeftIntensity = gray(texture2D(CC_Texture0, topLeftTextureCoordinate));
    float bottomRightIntensity = gray(texture2D(CC_Texture0, bottomRightTextureCoordinate));
    float leftIntensity = gray(texture2D(CC_Texture0, leftTextureCoordinate));
    float rightIntensity = gray(texture2D(CC_Texture0, rightTextureCoordinate));
    float bottomIntensity = gray(texture2D(CC_Texture0, bottomTextureCoordinate));
    float topIntensity = gray(texture2D(CC_Texture0, topTextureCoordinate));
    
    float h = -bottomLeftIntensity - 2.0 * leftIntensity - topLeftIntensity + bottomRightIntensity + 2.0 * rightIntensity + topRightIntensity;
    float v = -topLeftIntensity - 2.0 * topIntensity - topRightIntensity + bottomLeftIntensity + 2.0 * bottomIntensity + bottomRightIntensity;
    float mag = length(vec2(h, v));
    
    if ((leftIntensity-frontiere)*(rightIntensity - frontiere)<0.0 || (topIntensity-frontiere)*(bottomIntensity - frontiere)<0.0){
        gl_FragColor = vec4(1,1,1,1);
    }
    else{
        gl_FragColor = texture2D(CC_Texture0, v_texCoord);
    }
}
