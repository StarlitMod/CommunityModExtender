#pragma once

// ------------------------- Get -------------------------
template<typename T>
uintptr_t sdkClass<T>::Get() {
    return 0;
}

template<typename T>
uintptr_t sdkClass<T>::GetGot() {
    return 0; 
}

// ------------------------- Hook -------------------------
template<typename T>
void sdkClass<T>::Hook(void* new_func) {
    (void)new_func; 
}

template<typename T>
void sdkClass<T>::HookGot() {

}


template<typename T>
void sdkClass<T>::Unhook() {

}

// ------------------------- Pattern Scan -------------------------
template<typename T>
uintptr_t sdkClass<T>::Find(const std::string& pattern) {

    return 0;
}

template<typename T>
uintptr_t sdkClass<T>::FindAsm(const std::string& asmcode) {

    return 0;
}

// ------------------------- Write -------------------------
template<typename T>
void sdkClass<T>::Write(const void* value, size_t size) {

}
