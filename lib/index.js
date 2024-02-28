const addon = require('../build/Release/reproduction.node')

let buffer = Buffer.alloc(65535)
addon.test(buffer)
