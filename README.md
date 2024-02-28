# reproduction

To install dependencies:

```bash
npm install
```

To run:

```bash
npm run configure
npm run build
```

To test:

```bash
node lib/index.js
```

```bash
bun lib/index.js
```

Node output: 

```
start
end
```

Bun output:

```
Segmentation fault at address 0x0
...\src\binding.cpp:18:0: 0x7ffb2a071123 in Test (binding.obj)
    napi_get_buffer_info(env, argv[0], reinterpret_cast<void**>(&bufferData), nullptr);

???:?:?: 0x7ff719ccef5e in ??? (bun.exe)
???:?:?: 0x1c30000115d in ??? (???)
???:?:?: 0x1c30000111f in ??? (???)
```
