'use strict';
var cp = require('child_process');
var assert = require('assert');
var crash = require('..');

if (process.argv[2] === 'child') {
  crash();
  throw new Error('should not get here');
}

cp.spawn(process.execPath, [__filename, 'child'], { stdio: 'inherit' })
  .on('exit', function(code, signal) {
    if (process.platform === 'win32') {
      assert.strictEqual(~~code, ~~0xc0000005);
    } else {
      assert.strictEqual(signal, 'SIGSEGV');
    }
  });
