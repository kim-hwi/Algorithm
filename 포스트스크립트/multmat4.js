  /**
   * Multiplies two mat4s
   * 4x4 matrix represented as arr[16] with column major 
   *      matrixA[16] = [m0, m1, m2, m3, m4, ... m15] means matrix form of 
   *                   m0  m4  m8  m12
   *                   m1  m5  m9  m13      
   *                   m2  m6  m10 m14
   *                   m3  m7  m11 m15
   * @param {mat4} out the receiving matrix
   * @param {mat4} a the first operand
   * @param {mat4} b the second operand
   * @returns {mat4} out
   */

function multMat4(out, a, b) {
  
  var a00 = a[0], a01 = a[1], a02 = a[2], a03 = a[3],
    a10 = a[4], a11 = a[5], a12 = a[6], a13 = a[7],
    a20 = a[8], a21 = a[9], a22 = a[10], a23 = a[11],
    a30 = a[12], a31 = a[13], a32 = a[14], a33 = a[15];

  var b00 = b[0], b01 = b[1], b02 = b[2], b03 = b[3],
    b10 = b[4], b11 = b[5], b12 = b[6], b13 = b[7],
    b20 = b[8], b21 = b[9], b22 = b[10], b23 = b[11],
    b30 = b[12], b31 = b[13], b32 = b[14], b33 = b[15];

  var out00 = out[0], out01 = out[1], out02 = out[2], out03 = out[3],
    out10 = out[4], out11 = out[5], out12 = out[6], out13 = out[7],
    out20 = out[8], out21 = out[9], out22 = out[10], out23 = out[11],
    out30 = out[12], out31 = out[13], out32 = out[14], out33 = out[15];
      


  out[0] = a00 * b00 + a01 * b10 + a02 * b20 + a03 * b30;
  out[1] = a00 * b01 + a01 * b11 + a02 * b21 + a03 * b31;
  out[2] = a00 * b02 + a01 * b12 + a02 * b22 + a03 * b32;
  out[3] = a00 * b03 + a01 * b13 + a02 * b23 + a03 * b33;

  out[4] = a10 * b00 + a11 * b10 + a12 * b20 + a13 * b30;
  out[5] = a10 * b01 + a11 * b11 + a12 * b21 + a13 * b31;
  out[6] = a10 * b02 + a11 * b12 + a12 * b22 + a13 * b32;
  out[7] = a10 * b03 + a11 * b13 + a12 * b23 + a13 * b33;

  out[8] = a20 * b00 + a21 * b10 + a22 * b20 + a23 * b30;
  out[9] = a20 * b01 + a21 * b11 + a22 * b21 + a23 * b31;
  out[10] = a20 * b02 + a21 * b12 + a22 * b22 + a23 * b32;
  out[11] = a20 * b03 + a21 * b13 + a22 * b23 + a23 * b33;
  
  out[12] = a30 * b00 + a31 * b10 + a32 * b20 + a33 * b30;
  out[13] = a30 * b01 + a31 * b11 + a32 * b21 + a33 * b31;
  out[14] = a30 * b02 + a31 * b12 + a32 * b22 + a33 * b32;
  out[15] = a30 * b03 + a31 * b13 + a32 * b23 + a33 * b33;

    return out;
  }


function main() {
	ma =   [1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 2];
	mb =   [1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 2];
	mout = [0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
	multMat4(mout, ma, mb);  
	console.log(mout);
}
		