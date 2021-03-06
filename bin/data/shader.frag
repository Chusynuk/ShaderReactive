#ifdef GL_ES
precision mediump float;
#endif

uniform float u_time;
uniform vec2 u_resolution;

// CIRCLES

void main(){
    vec2 coord = gl_FragCoord.xy / u_resolution;
    vec3 color = vec3(0.0);
    vec2 translate = vec2(-0.5);
    coord += translate;

    color.r += abs(0.1 + length(coord) - 0.6 * abs(sin(u_time * 5.9)));
    color.g += abs(0.1 + length(coord) - 0.6 * abs(sin(u_time * 0.6)));
    color.b += abs(0.1 + length(coord) - 0.6 * abs(sin(u_time * 8.8)));
    

    gl_FragColor = vec4(0.05 / color, 1.0);
}
