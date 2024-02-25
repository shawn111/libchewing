/*
 * Copyright (c) 2023
 *      libchewing Core Team. See ChangeLog for details.
 *
 * See the file "COPYING" for information on usage and redistribution
 * of this file.
 */

#ifndef chewing_public_bindings_h
#define chewing_public_bindings_h

#pragma once

/* Warning, this file is autogenerated by cbindgen. Don't modify this manually. */

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

/** @brief context handle used for Chewing IM APIs
 */
typedef struct ChewingContext ChewingContext;

/* specified to Chewing API */
#if defined(_WIN32) || defined(_WIN64) || defined(_WIN32_WCE)
#    define CHEWING_DLL_IMPORT __declspec(dllimport)
#    define CHEWING_DLL_EXPORT __declspec(dllexport)
#    ifdef CHEWINGDLL_EXPORTS
#        define CHEWING_API CHEWING_DLL_EXPORT
#        define CHEWING_PRIVATE
#    elif CHEWINGDLL_IMPORTS
#        define CHEWING_API CHEWING_DLL_IMPORT
#        define CHEWING_PRIVATE
#    else
#        define CHEWING_API
#        define CHEWING_PRIVATE
#    endif
#elif (__GNUC__ > 3) && (defined(__ELF__) || defined(__PIC__))
#    define CHEWING_API __attribute__((__visibility__("default")))
#    define CHEWING_PRIVATE __attribute__((__visibility__("hidden")))
#else
#    define CHEWING_API
#    define CHEWING_PRIVATE
#endif

#ifndef UNUSED
#    if defined(__GNUC__)       /* gcc specific */
#        define UNUSED __attribute__((unused))
#    else
#        define UNUSED
#    endif
#endif

#ifndef DEPRECATED
#    if defined(__GNUC__) && __GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 1) /* gcc specific */
#        define DEPRECATED __attribute__((deprecated))
#        if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 5)
#            define DEPRECATED_FOR(f) __attribute__((deprecated("Use " #f " instead")))
#        else
#            define DEPRECATED_FOR(f) DEPRECATED
#        endif
#    else
#        define DEPRECATED
#        define DEPRECATED_FOR(f)
#    endif
#endif


#define CHINESE_MODE 1

#define SYMBOL_MODE 0

#define FULLSHAPE_MODE 1

#define HALFSHAPE_MODE 0

#define AUTOLEARN_DISABLED 1

#define AUTOLEARN_ENABLED 0

#define MIN_SELKEY 1

#define MAX_SELKEY 10

#define CHEWING_LOG_VERBOSE 1

#define CHEWING_LOG_DEBUG 2

#define CHEWING_LOG_INFO 3

#define CHEWING_LOG_WARN 4

#define CHEWING_LOG_ERROR 5

/**
 * Use "asdfjkl789" as selection key
 */
#define HSU_SELKEY_TYPE1 1

/**
 * Use "asdfzxcv89" as selection key
 */
#define HSU_SELKEY_TYPE2 2

typedef enum KB {
  KB_DEFAULT,
  KB_HSU,
  KB_IBM,
  KB_GIN_YIEH,
  KB_ET,
  KB_ET26,
  KB_DVORAK,
  KB_DVORAK_HSU,
  KB_DACHEN_CP26,
  KB_HANYU_PINYIN,
  KB_THL_PINYIN,
  KB_MPS2_PINYIN,
  KB_CARPALX,
  KB_COLEMAK_DH_ANSI,
  KB_COLEMAK_DH_ORTH,
  KB_TYPE_NUM,
} KB;

typedef struct ChewingContext ChewingContext;

typedef struct IntervalType {
  /**
   * Starting position of certain interval
   */
  int from;
  /**
   * Ending position of certain interval (exclusive)
   */
  int to;
} IntervalType;

/**
 * Deprecated, use chewing_set_ series of functions to set parameters instead.
 */
typedef struct ChewingConfigData {
  int candPerPage;
  int maxChiSymbolLen;
  int selKey[MAX_SELKEY];
  int bAddPhraseForward;
  int bSpaceAsSelection;
  int bEscCleanAllBuf;
  int bAutoShiftCur;
  int bEasySymbolInput;
  int bPhraseChoiceRearward;
  int hsuSelKeyType;
} ChewingConfigData;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

struct ChewingContext *chewing_new(void);

void chewing_delete(struct ChewingContext *ctx);

void chewing_free(void *ptr);

int chewing_Reset(struct ChewingContext *ctx);

int chewing_set_KBType(struct ChewingContext *ctx, int kbtype);

int chewing_get_KBType(const struct ChewingContext *ctx);

char *chewing_get_KBString(const struct ChewingContext *ctx);

int chewing_KBStr2Num(const char *str);

void chewing_set_ChiEngMode(struct ChewingContext *ctx, int mode);

int chewing_get_ChiEngMode(const struct ChewingContext *ctx);

void chewing_set_ShapeMode(struct ChewingContext *ctx, int mode);

int chewing_get_ShapeMode(const struct ChewingContext *ctx);

void chewing_set_candPerPage(struct ChewingContext *ctx, int n);

int chewing_get_candPerPage(const struct ChewingContext *ctx);

void chewing_set_maxChiSymbolLen(struct ChewingContext *ctx, int n);

int chewing_get_maxChiSymbolLen(const struct ChewingContext *ctx);

void chewing_set_selKey(struct ChewingContext *ctx, const int *sel_keys, int len);

int *chewing_get_selKey(const struct ChewingContext *ctx);

void chewing_set_addPhraseDirection(struct ChewingContext *ctx, int direction);

int chewing_get_addPhraseDirection(const struct ChewingContext *ctx);

void chewing_set_spaceAsSelection(struct ChewingContext *ctx, int mode);

int chewing_get_spaceAsSelection(const struct ChewingContext *ctx);

void chewing_set_escCleanAllBuf(struct ChewingContext *ctx, int mode);

int chewing_get_escCleanAllBuf(const struct ChewingContext *ctx);

void chewing_set_autoShiftCur(struct ChewingContext *ctx, int mode);

int chewing_get_autoShiftCur(const struct ChewingContext *ctx);

void chewing_set_easySymbolInput(struct ChewingContext *ctx, int mode);

int chewing_get_easySymbolInput(const struct ChewingContext *ctx);

void chewing_set_phraseChoiceRearward(struct ChewingContext *ctx, int mode);

int chewing_get_phraseChoiceRearward(const struct ChewingContext *ctx);

void chewing_set_autoLearn(struct ChewingContext *ctx, int mode);

int chewing_get_autoLearn(const struct ChewingContext *ctx);

unsigned short *chewing_get_phoneSeq(const struct ChewingContext *ctx);

int chewing_get_phoneSeqLen(const struct ChewingContext *ctx);

int chewing_userphrase_enumerate(struct ChewingContext *ctx);

int chewing_userphrase_has_next(struct ChewingContext *ctx,
                                unsigned int *phrase_len,
                                unsigned int *bopomofo_len);

int chewing_userphrase_get(struct ChewingContext *ctx,
                           char *phrase_buf,
                           unsigned int phrase_len,
                           char *bopomofo_buf,
                           unsigned int bopomofo_len);

int chewing_userphrase_add(struct ChewingContext *ctx,
                           const char *phrase_buf,
                           const char *bopomofo_buf);

int chewing_userphrase_remove(struct ChewingContext *ctx,
                              const char *phrase_buf,
                              const char *bopomofo_buf);

int chewing_userphrase_lookup(struct ChewingContext *ctx,
                              const char *phrase_buf,
                              const char *bopomofo_buf);

int chewing_cand_list_first(struct ChewingContext *ctx);

int chewing_cand_list_last(struct ChewingContext *ctx);

int chewing_cand_list_has_next(struct ChewingContext *ctx);

int chewing_cand_list_has_prev(struct ChewingContext *ctx);

int chewing_cand_list_next(struct ChewingContext *ctx);

int chewing_cand_list_prev(struct ChewingContext *ctx);

int chewing_commit_preedit_buf(struct ChewingContext *ctx);

int chewing_clean_preedit_buf(struct ChewingContext *ctx);

int chewing_clean_bopomofo_buf(struct ChewingContext *ctx);

int chewing_phone_to_bopomofo(unsigned short phone, char *buf, unsigned short len);

int chewing_handle_Space(struct ChewingContext *ctx);

int chewing_handle_Esc(struct ChewingContext *ctx);

int chewing_handle_Enter(struct ChewingContext *ctx);

int chewing_handle_Del(struct ChewingContext *ctx);

int chewing_handle_Backspace(struct ChewingContext *ctx);

int chewing_handle_Tab(struct ChewingContext *ctx);

int chewing_handle_ShiftLeft(struct ChewingContext *ctx);

int chewing_handle_Left(struct ChewingContext *ctx);

int chewing_handle_ShiftRight(struct ChewingContext *ctx);

int chewing_handle_Right(struct ChewingContext *ctx);

int chewing_handle_Up(struct ChewingContext *ctx);

int chewing_handle_Home(struct ChewingContext *ctx);

int chewing_handle_End(struct ChewingContext *ctx);

int chewing_handle_PageUp(struct ChewingContext *ctx);

int chewing_handle_PageDown(struct ChewingContext *ctx);

int chewing_handle_Down(struct ChewingContext *ctx);

int chewing_handle_Capslock(struct ChewingContext *ctx);

int chewing_handle_Default(struct ChewingContext *ctx, int key);

int chewing_handle_CtrlNum(struct ChewingContext *ctx, int key);

int chewing_handle_ShiftSpace(struct ChewingContext *ctx);

int chewing_handle_DblTab(struct ChewingContext *ctx);

int chewing_handle_Numlock(struct ChewingContext *ctx, int key);

int chewing_commit_Check(const struct ChewingContext *ctx);

char *chewing_commit_String(const struct ChewingContext *ctx);

const char *chewing_commit_String_static(const struct ChewingContext *ctx);

char *chewing_buffer_String(const struct ChewingContext *ctx);

const char *chewing_buffer_String_static(const struct ChewingContext *ctx);

int chewing_buffer_Check(const struct ChewingContext *ctx);

int chewing_buffer_Len(const struct ChewingContext *ctx);

const char *chewing_bopomofo_String_static(const struct ChewingContext *ctx);

int chewing_bopomofo_Check(const struct ChewingContext *ctx);

int chewing_cursor_Current(const struct ChewingContext *ctx);

int chewing_cand_CheckDone(const struct ChewingContext *ctx);

int chewing_cand_TotalPage(const struct ChewingContext *ctx);

int chewing_cand_ChoicePerPage(const struct ChewingContext *ctx);

int chewing_cand_TotalChoice(const struct ChewingContext *ctx);

int chewing_cand_CurrentPage(const struct ChewingContext *ctx);

void chewing_cand_Enumerate(struct ChewingContext *ctx);

int chewing_cand_hasNext(struct ChewingContext *ctx);

char *chewing_cand_String(struct ChewingContext *ctx);

const char *chewing_cand_String_static(struct ChewingContext *ctx);

char *chewing_cand_string_by_index(struct ChewingContext *ctx, int index);

const char *chewing_cand_string_by_index_static(struct ChewingContext *ctx, int index);

int chewing_cand_choose_by_index(struct ChewingContext *ctx, int index);

int chewing_cand_open(struct ChewingContext *ctx);

int chewing_cand_close(struct ChewingContext *ctx);

void chewing_interval_Enumerate(struct ChewingContext *ctx);

int chewing_interval_hasNext(struct ChewingContext *ctx);

void chewing_interval_Get(struct ChewingContext *ctx, struct IntervalType *it);

int chewing_aux_Check(const struct ChewingContext *ctx);

int chewing_aux_Length(const struct ChewingContext *ctx);

char *chewing_aux_String(const struct ChewingContext *ctx);

const char *chewing_aux_String_static(const struct ChewingContext *ctx);

int chewing_keystroke_CheckIgnore(const struct ChewingContext *ctx);

int chewing_keystroke_CheckAbsorb(const struct ChewingContext *ctx);

int chewing_kbtype_Total(const struct ChewingContext *_ctx);

void chewing_kbtype_Enumerate(struct ChewingContext *ctx);

int chewing_kbtype_hasNext(struct ChewingContext *ctx);

char *chewing_kbtype_String(struct ChewingContext *ctx);

const char *chewing_kbtype_String_static(struct ChewingContext *ctx);

int chewing_zuin_Check(const struct ChewingContext *ctx);

char *chewing_zuin_String(const struct ChewingContext *ctx, int *zuin_count);

int chewing_Init(const char *data_path, const char *hash_path);

void chewing_Terminate(void);

int chewing_Configure(struct ChewingContext *ctx, struct ChewingConfigData *pcd);

void chewing_set_hsuSelKeyType(struct ChewingContext *_ctx, int mode);

int chewing_get_hsuSelKeyType(struct ChewingContext *_ctx);

uint16_t UintFromPhone(const char *phone);

int get_search_path(char *path, uintptr_t path_len);

int find_path_by_files(const char *search_path,
                       const char *const *files,
                       char *output,
                       uintptr_t output_len);

int ueStrLen(const char *str);

int ueBytesFromChar(unsigned char b);

int ueStrNBytes(const char *str, int n);

int ueStrNCpy(char *dest, const char *src, uintptr_t n, int end);

char *ueStrSeek(char *src, uintptr_t n);

const char *ueConstStrSeek(const char *src, uintptr_t n);

const char *ueStrStr(const char *str, uintptr_t _lstr, const char *substr, uintptr_t _lsub);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif /* chewing_public_bindings_h */
