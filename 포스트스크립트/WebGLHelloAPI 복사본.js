var gl; //전역변수 생성-es랑 비슷한 느낌 만들수 잇음

function testGLError(functionLastCalled) { 
    //gl은 에러가나면 그냥진행한다. ex-배틀그라운드 -최근에 발생한 에러 lasterror에 저장

    var lastError = gl.getError();

    if (lastError != gl.NO_ERROR) {
        alert(functionLastCalled + " failed (" + lastError + ")");
        return false;
    }

    return true;
}

function initialiseGL(canvas) {
    try {//일단해봐
        // Try to grab the standard context. If it fails, fallback to experimental
        gl = canvas.getContext("webgl") || canvas.getContext("experimental-webgl");
        // 캔버스가 파라메타로 넘어옴 getcontext-거대한 스테이트들의 모임을 컨텍스트라고함.
        // 컨텍스트를 받기위해 바로 위의 레이어에 요청함. 그것이 캔버스이다.
        // webgl을 사용하겟다.
        // || 가 들어간 이유는 앞에게 안되면 뒤에꺼를 실행해라. webgl의 일부분만 지원하는 브라우저를위해
        gl.viewport(0, 0, canvas.width, canvas.height);
        //html에서 지정한 500,800등의 크기.- 여기서만 줄이면 화면은 그대로이고, 그림만 줄어든다.
        //그림의 일부분만 사용가능하다.-클리핑
    }
    catch (e) {
    }

    if (!gl) {
        alert("Unable to initialise WebGL. Your browser may not support it");
        return false;//webgl호출 실패시
    }

    return true;
}

var shaderProgram;

function initialiseBuffer() {

    var vertexData = [
        -0.4, -0.4, 0.0,  1.0, 0.0, 0.0 ,1.0,// Bottom left
         0.4, -0.4, 0.0,  0.0, 1.0, 0.0, 1.0,// Bottom right
         0.0, 0.4, 0.0,  0.0, 0.0, 1.0, 1.0, // Top middle
         0.0, 0.0, 0.0,  1.0, 1.0, 1.0, 1.0,
         0.5, 0.0, 0.0,  1.0, 1.0, 1.0, 1.0,
         0.25, 0.7, 0.0,  0.0, 0.0, 0.0, 1.0
    ];

    // Generate a buffer object
    gl.vertexBuffer = gl.createBuffer();

    // Bind buffer as a vertex buffer so we can fill it with data
    gl.bindBuffer(gl.ARRAY_BUFFER, gl.vertexBuffer);

    gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(vertexData), gl.STATIC_DRAW);

    return testGLError("initialiseBuffers");
}

function initialiseShaders() {

    var fragmentShaderSource = '\
			varying highp vec4 col;\
            void main(void) \
			{ \
				gl_FragColor = vec4(1.0,0.0,0.0,1.0); \
			}';

    // Create the fragment shader object
    gl.fragShader = gl.createShader(gl.FRAGMENT_SHADER);

    // Load the source code into it
    gl.shaderSource(gl.fragShader, fragmentShaderSource);

    // Compile the source code
    gl.compileShader(gl.fragShader);

    // Check if compilation succeeded
    if (!gl.getShaderParameter(gl.fragShader, gl.COMPILE_STATUS)) {
        // It didn't. Display the info log as to why
        alert("Failed to compile the fragment shader.\n" + gl.getShaderInfoLog(gl.fragShader));
        return false;
    }

    /*	Concept: Vertex Shaders
        Vertex shaders primarily exist to allow a developer to express how to orient vertices in 3D space, through transformations like 
        Scaling, Translation or Rotation. Using the same basic layout and structure as a fragment shader, these take in vertex data and 
        output a fully transformed set of positions. Other inputs are also able to be used such as normals or texture coordinates, and can 
        also be transformed and output alongside the position data.
    */

    // Vertex shader code
    var vertexShaderSource = '\
			attribute highp vec4 myVertex; \
            attribute highp vec4 myColor; \
            varying highp vec4 col;\
			uniform mediump mat4 transformationMatrix; \
			void main(void)  \
			{ \
                col = myColor;\
				gl_Position = transformationMatrix * myVertex; \
			}';

    // Create the vertex shader object
    gl.vertexShader = gl.createShader(gl.VERTEX_SHADER);

    // Load the source code into it
    gl.shaderSource(gl.vertexShader, vertexShaderSource);

    // Compile the source code
    gl.compileShader(gl.vertexShader);

    // Check if compilation succeeded
    if (!gl.getShaderParameter(gl.vertexShader, gl.COMPILE_STATUS)) {
        // It didn't. Display the info log as to why
        alert("Failed to compile the vertex shader.\n" + gl.getShaderInfoLog(gl.vertexShader));
        return false;
    }

    // Create the shader program
    gl.programObject = gl.createProgram();

    // Attach the fragment and vertex shaders to it
    gl.attachShader(gl.programObject, gl.fragShader);
    gl.attachShader(gl.programObject, gl.vertexShader);

    // Bind the custom vertex attribute "myVertex" to location 0
    gl.bindAttribLocation(gl.programObject, 0, "myVertex");
    gl.bindAttribLocation(gl.programObject, 1, "myColor");

    // Link the program
    gl.linkProgram(gl.programObject);

    // Check if linking succeeded in a similar way we checked for compilation errors
    if (!gl.getProgramParameter(gl.programObject, gl.LINK_STATUS)) {
        alert("Failed to link the program.\n" + gl.getProgramInfoLog(gl.programObject));
        return false;
    }

    /*	Use the Program
        Calling gl.useProgram tells WebGL that the application intends to use this program for rendering. Now that it's installed into
        the current state, any further gl.draw* calls will use the shaders contained within it to process scene data. Only one program can
        be active at once, so in a multi-program application this function would be called in the render loop. Since this application only
        uses one program it can be installed in the current state and left there.
    */
    gl.useProgram(gl.programObject);

    return testGLError("initialiseShaders");
}

var rrr = 0.0;
var rinc = 0.00;

function renderScene() {
    
    gl.clearColor(rrr, 0.0, 0.0, 1.0);
     rrr = rrr + rinc;
     if(rrr > 1.0) 
        rinc = -0.01;
     if(rrr < 0.0) 
        rinc = 0.01;

    gl.clear(gl.COLOR_BUFFER_BIT);

    // Get the location of the transformation matrix in the shader using its name
    var matrixLocation = gl.getUniformLocation(gl.programObject, "transformationMatrix");
    var colLocation = gl.getUniformLocation(gl.programObject, "col");
    // Matrix used to specify the orientation of the triangle on screen
    var transformationMatrix = [
        1.0, 0.0, 0.0, 0.0,
        0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 1.0
    ];

    var cColor = [1.0, 0.0, 0.0, 1.0];
    // Pass the identity transformation matrix to the shader using its location
    gl.uniformMatrix4fv(matrixLocation, gl.FALSE, transformationMatrix);

    if (!testGLError("gl.uniformMatrix4fv")) {
        return false;
    }

    gl.enableVertexAttribArray(0);
    gl.vertexAttribPointer(0, 3, gl.FLOAT, gl.FALSE, 28, 0);
    gl.enableVertexAttribArray(1);
    gl.vertexAttribPointer(1, 4, gl.FLOAT, gl.FALSE, 28, 12);

    gl.vetexATTRib4f(1, 1.0, 0.0, 0.0, 1.0);
    //
    //
    if (!testGLError("gl.vertexAttribPointer")) {
        return false;
    }

    gl.drawArrays(gl.TRIANGLES, 0, 3);

    if (!testGLError("gl.drawArrays")) {
        return false;
    }

    return true;
}

function main() {
    var canvas = document.getElementById("helloapicanvas"); 
    // 지역변수 캔버스와 helloapicanvas는 html에서의 id 와 같아야함

    if (!initialiseGL(canvas)) {//트루펄스 리턴- 에러발생시 리턴해버림
        return;
    }

    if (!initialiseBuffer()) {//트루펄스 리턴- 에러발생시 리턴해버림
        return;
    }

    if (!initialiseShaders()) {//트루펄스 리턴- 에러발생시 리턴해버림
        return;
    }

    // Render loop - 매우복잡함
    requestAnimFrame = (function () {
        return window.requestAnimationFrame || window.webkitRequestAnimationFrame || window.mozRequestAnimationFrame ||
			function (callback) {
			    window.setTimeout(callback, 1000, 60);
			};
    })();

    (function renderLoop() {
        if (renderScene()) {
            // Everything was successful, request that we redraw our scene again in the future
            requestAnimFrame(renderLoop);
        }
    })();
}
