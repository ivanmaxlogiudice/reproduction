#include <node_api.h>
#include <stdio.h>

napi_value Test(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    bool isBuffer;
    napi_is_buffer(env, argv[0], &isBuffer);
    if (!isBuffer) {
        napi_throw_error(env, nullptr, "Not a buffer.");
        return nullptr;
    }

    printf("start\n");
    char* bufferData;
    napi_get_buffer_info(env, argv[0], reinterpret_cast<void**>(&bufferData), nullptr);
    printf("end\n");
    
    return nullptr;
}

napi_value Init(napi_env env, napi_value exports) {   
    napi_value fn;

    // Test
    if (napi_ok != napi_create_function(env, "test", NAPI_AUTO_LENGTH, Test, NULL, &fn)) return NULL;
    if (napi_ok != napi_set_named_property(env, exports, "test", fn)) return NULL;

    return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
