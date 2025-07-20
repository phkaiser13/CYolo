// src/ort_wrapper.c
#include <stdio.h>
#include <stdlib.h>
#include <onnxruntime_c_api.h>
#include "ort_wrapper.h"

static const OrtApi* ort = NULL;
static OrtEnv* env = NULL;
static OrtSession* session = NULL;
static OrtSessionOptions* session_options = NULL;

bool ort_initialize() {
    ort = OrtGetApiBase()->GetApi(ORT_API_VERSION);
    if (!ort) {
        fprintf(stderr, "[ORT] Falha ao obter API base.\n");
        return false;
    }

    if (ort->CreateEnv(ORT_LOGGING_LEVEL_WARNING, "yolo_env", &env) != NULL) {
        fprintf(stderr, "[ORT] Falha ao criar ambiente.\n");
        return false;
    }

    if (ort->CreateSessionOptions(&session_options) != NULL) {
        fprintf(stderr, "[ORT] Falha ao criar opções de sessão.\n");
        return false;
    }

    // Habilita otimizações de desempenho (nível 3)
    ort->SetSessionGraphOptimizationLevel(session_options, ORT_ENABLE_EXTENDED);
    return true;
}

bool ort_load_model(const char* model_path) {
    if (!env || !session_options) return false;

    if (ort->CreateSession(env, model_path, session_options, &session) != NULL) {
        fprintf(stderr, "[ORT] Falha ao carregar o modelo: %s\n", model_path);
        return false;
    }

    return true;
}

void ort_cleanup() {
    if (session) ort->ReleaseSession(session);
    if (session_options) ort->ReleaseSessionOptions(session_options);
    if (env) ort->ReleaseEnv(env);

    session = NULL;
    session_options = NULL;
    env = NULL;
}
