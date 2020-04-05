#ifdef GL_ES
precision mediump float;
#endif

uniform float u_time;
uniform vec2 u_resolution;
uniform vec2 u_mouse;

// CIRCLES

// void main(){
//     vec2 coord = gl_FragCoord.xy / u_resolution;
//     vec3 color = vec3(0.0);
//     vec2 translate = vec2(-0.5);
//     coord += translate;

//     color.r += abs(0.1 + length(coord) - 0.6 * abs(sin(u_time * 0.9 / 12.0)));
//     color.g += abs(0.1 + length(coord) - 0.6 * abs(sin(u_time * 0.6 / 4.0)));
//     color.b += abs(0.1 + length(coord) - 0.6 * abs(sin(u_time * 0.8 / 9.0)));
    

//     gl_FragColor = vec4(0.05 / color, 1.0);
// }

//  COLORS

void main() {
    vec2 st = gl_FragCoord.xy/u_resolution.xy;
    st.x *= u_resolution.x/u_resolution.y;

    vec3 color = vec3(0.);
    color = vec3(st.x,st.y,st.x);

    gl_FragColor = vec4(color,u_time);
}