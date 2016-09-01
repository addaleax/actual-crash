'use strict';
var cp = require('child_process');
var assert = require('assert');
var crash = require('..');

if (process.argv[2] === 'child') {
  crash();
  throw new Error('should not get here');
}

cp.spawn(process.execPath, [__filename, 'child'])
  .on('exit', function(code, signal) {
    assert.strictEqual(code, null);
    assert.strictEqual(signal, 'SIGSEGV');
  });
