/*
 * Copyright (c) 2022
 *      libchewing Core Team. See ChangeLog for details.
 *
 * See the file "COPYING" for information on usage and redistribution
 * of this file.
 */

#ifndef chewing_internal_bindings_h
#define chewing_internal_bindings_h

#pragma once

/* Warning, this file is autogenerated by cbindgen. Don't modify this manually. */

#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include "chewing_rs.h"

#define MAX_UTF8_SIZE 4

#define MAX_UTF8_BUF (MAX_UTF8_SIZE + 1)

#define BOPOMOFO_SIZE 4

#define MAX_BOPOMOFO_UTF8_BUF ((BOPOMOFO_SIZE * MAX_UTF8_SIZE) + 1)

#define PINYIN_SIZE 10

#define MAX_PHRASE_LEN 11

#define MAX_PHRASE_UTF8_BUF ((MAX_PHRASE_LEN * MAX_UTF8_SIZE) + 1)

#define MAX_PHONE_SEQ_LEN 50

#define MAX_PHONE_SEQ_BUF (MAX_PHONE_SEQ_LEN + 1)

#define MAX_PHONE_SEQ_UTF8_BUF ((MAX_PHONE_SEQ_LEN * MAX_UTF8_SIZE) + 1)

#define MIN_CHI_SYMBOL_LEN 0

#define MAX_CHI_SYMBOL_LEN (MAX_PHONE_SEQ_LEN - MAX_PHRASE_LEN)

#define MAX_INTERVAL (((MAX_PHONE_SEQ_LEN + 1) * MAX_PHONE_SEQ_LEN) / 2)

#define MAX_CHOICE 567

#define MAX_CHOICE_BUF 50

#define EASY_SYMBOL_KEY_TAB_LEN 36

#define AUX_PREFIX_LEN 3

#define MAX_SHOW_MSG_BUF ((MAX_UTF8_SIZE * (MAX_PHRASE_LEN + AUX_PREFIX_LEN)) + 1)

#define N_HASH_BIT 14

#define HASH_TABLE_SIZE (1 << N_HASH_BIT)

#define WORD_CHOICE 0

#define SYMBOL_CATEGORY_CHOICE 1

#define SYMBOL_CHOICE_INSERT 2

#define SYMBOL_CHOICE_UPDATE 3

typedef enum BOPOMOFO {
  BOPOMOFO_IGNORE,
  BOPOMOFO_ABSORB,
  BOPOMOFO_COMMIT,
  BOPOMOFO_KEY_ERROR,
  BOPOMOFO_ERROR,
  BOPOMOFO_NO_WORD,
  BOPOMOFO_OPEN_SYMBOL_TABLE,
} BOPOMOFO;

typedef enum Category {
  CHEWING_NONE,
  CHEWING_CHINESE,
  CHEWING_SYMBOL,
} Category;

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
  KB_TYPE_NUM,
} KB;

/**
 * TODO: docs
 * TODO: move this to the editor module
 */
typedef enum KeyBehavior {
  /**
   * TODO: docs
   */
  IGNORE = 0,
  /**
   * TODO: docs
   */
  ABSORB,
  /**
   * TODO: docs
   */
  COMMIT,
  /**
   * TODO: docs
   */
  KEY_ERROR,
  /**
   * TODO: docs
   */
  ERROR,
  /**
   * TODO: docs
   */
  NO_WORD,
  /**
   * TODO: docs
   */
  OPEN_SYMBOL_TABLE,
} KeyBehavior;

/**
 * TODO: docs
 */
typedef enum KeyboardLayoutCompat {
  /**
   * TODO: docs
   */
  DEFAULT = 0,
  /**
   * TODO: docs
   */
  HSU,
  /**
   * TODO: docs
   */
  IBM,
  /**
   * TODO: docs
   */
  GIN_YIEH,
  /**
   * TODO: docs
   */
  ET,
  /**
   * TODO: docs
   */
  ET26,
  /**
   * TODO: docs
   */
  DVORAK,
  /**
   * TODO: docs
   */
  DVORAK_HSU,
  /**
   * TODO: docs
   */
  DACHEN_CP26,
  /**
   * TODO: docs
   */
  HANYU_PINYIN,
  /**
   * TODO: docs
   */
  THL_PINYIN,
  /**
   * TODO: docs
   */
  MPS2_PINYIN,
  /**
   * TODO: docs
   */
  CARPALX,
} KeyboardLayoutCompat;

enum UserUpdate
#ifdef __cplusplus
  : uint8_t
#endif // __cplusplus
 {
  USER_UPDATE_INSERT = 1,
  USER_UPDATE_MODIFY = 2,
  USER_UPDATE_FAIL = 4,
};
#ifndef __cplusplus
typedef uint8_t UserUpdate;
#endif // __cplusplus

/**
 * TODO: doc
 */
typedef struct ChewingConversionEngine ChewingConversionEngine;

/**
 * A collection of dictionaries that returns the union of the lookup results.
 * # Examples
 *
 * ```
 * # fn main() -> Result<(), Box<dyn std::error::Error>> {
 * use std::collections::{HashMap, HashSet};
 *
 * use chewing::{dictionary::{LayeredDictionary, Dictionary}, syl, zhuyin::Bopomofo};
 *
 * let mut sys_dict = Box::new(HashMap::new());
 * let mut user_dict = Box::new(HashMap::new());
 * sys_dict.insert(
 *     vec![syl![Bopomofo::C, Bopomofo::E, Bopomofo::TONE4]],
 *     vec![("測", 1).into(), ("冊", 1).into(), ("側", 1).into()]
 * );
 * user_dict.insert(
 *     vec![syl![Bopomofo::C, Bopomofo::E, Bopomofo::TONE4]],
 *     vec![("策", 100).into(), ("冊", 100).into()]
 * );
 *
 * let user_block_list = Box::new(HashSet::from(["側".to_string()]));
 *
 * let dict = LayeredDictionary::new(vec![sys_dict, user_dict], vec![user_block_list]);
 * assert_eq!(
 *     [
 *         ("策", 100).into(),
 *         ("冊", 100).into(),
 *         ("測", 1).into(),
 *     ]
 *     .into_iter()
 *     .collect::<HashSet<_>>(),
 *     dict.lookup_phrase(&[
 *         syl![Bopomofo::C, Bopomofo::E, Bopomofo::TONE4]
 *     ])
 *     .collect::<HashSet<_>>(),
 * );
 * # Ok(())
 * # }
 * ```
 */
typedef struct LayeredDictionary LayeredDictionary;

typedef struct SyllableEditorWithKeymap SyllableEditorWithKeymap;

typedef struct TreeType TreeType;

typedef struct UserphraseDbAndEstimate UserphraseDbAndEstimate;

typedef struct AvailInfoAvail {
  int len;
  const void *id;
} AvailInfoAvail;

/**
 * Information of available phrase or character choices.
 */
typedef struct AvailInfo {
  /**
   * All kinds of lengths of available phrases.
   */
  struct AvailInfoAvail avail[MAX_PHRASE_LEN];
  /**
   * Total number of available lengths.
   */
  int nAvail;
  /**
   * The current choosing available length.
   */
  int currentAvail;
} AvailInfo;

typedef struct ChoiceInfo {
  /**
   * Total page number.
   */
  int nPage;
  /**
   * Current page number.
   */
  int pageNo;
  /**
   * Number of choices per page.
   */
  int nChoicePerPage;
  /**
   * Store possible phrases for being chosen.
   */
  char totalChoiceStr[MAX_CHOICE][MAX_PHRASE_UTF8_BUF];
  /**
   * Number of phrases to choose.
   */
  int nTotalChoice;
  int oldChiSymbolCursor;
  int isSymbol;
} ChoiceInfo;

typedef struct PhrasingOutput {
  IntervalType dispInterval[MAX_INTERVAL];
  int nDispInterval;
  int nNumCut;
} PhrasingOutput;

typedef struct BopomofoData {
  struct SyllableEditorWithKeymap *editorWithKeymap;
} BopomofoData;

typedef struct PreeditBuf {
  enum Category category;
  uint8_t char_[MAX_UTF8_BUF];
} PreeditBuf;

typedef struct UserPhraseData {
  uint16_t phoneSeq[MAX_PHONE_SEQ_LEN];
  char wordSeq[MAX_PHRASE_UTF8_BUF];
  int userfreq;
  int recentTime;
  int origfreq;
  int maxfreq;
} UserPhraseData;

typedef struct SymbolEntry {
  /**
   * Total number of symbols in the category.
   *
   * If n_symbols = 0, the category is treat as a symbol,
   * which is a zero-terminated utf-8 string.
   *
   * In that case, `symbols` is unused and isn't allocated at all.
   */
  int nSymbols;
  /**
   * Category name of the symbols.
   */
  char category[MAX_PHRASE_UTF8_BUF];
  char symbols[0][MAX_UTF8_BUF];
} SymbolEntry;

typedef struct ChewingStaticData {
  unsigned int nSymbolEntry;
  struct SymbolEntry **symbolTable;
  char *gEasySymbolValue[EASY_SYMBOL_KEY_TAB_LEN];
  int gEasySymbolNum[EASY_SYMBOL_KEY_TAB_LEN];
} ChewingStaticData;

typedef struct ChewingData {
  struct AvailInfo availInfo;
  struct ChoiceInfo choiceInfo;
  struct PhrasingOutput phrOut;
  struct BopomofoData bopomofoData;
  ChewingConfigData config;
  /**
   * Current input buffer, content == 0 means Chinese code
   */
  struct PreeditBuf preeditBuf[MAX_PHONE_SEQ_LEN];
  int chiSymbolCursor;
  int chiSymbolBufLen;
  int pointStart;
  int pointEnd;
  int bShowMsg;
  char showMsg[MAX_SHOW_MSG_BUF];
  int showMsgLen;
  uint16_t phoneSeq[MAX_PHONE_SEQ_LEN];
  uint16_t phoneSeqAlt[MAX_PHONE_SEQ_LEN];
  int nPhoneSeq;
  char selectStr[MAX_PHONE_SEQ_LEN][MAX_PHRASE_UTF8_BUF];
  IntervalType selectInterval[MAX_PHONE_SEQ_LEN];
  int nSelect;
  IntervalType preferInterval[MAX_INTERVAL];
  int nPrefer;
  int bUserArrCnnct[MAX_PHONE_SEQ_BUF];
  int bUserArrBrkpt[MAX_PHONE_SEQ_BUF];
  int bArrBrkpt[MAX_PHONE_SEQ_BUF];
  int bSymbolArrBrkpt[MAX_PHONE_SEQ_BUF];
  int bChiSym;
  int bSelect;
  int bFirstKey;
  int bFullShape;
  char symbolKeyBuf[MAX_PHONE_SEQ_LEN];
  struct UserPhraseData userphraseData;
  struct ChewingStaticData staticData;
  void (*logger)(void *data, int level, const char *fmt);
  void *loggerData;
  const struct LayeredDictionary *dict;
  struct ChewingConversionEngine *ce;
  struct UserphraseDbAndEstimate *ue;
  void *phraseIter;
} ChewingData;

typedef struct Phrase {
  char phrase[MAX_PHONE_SEQ_BUF];
  int freq;
} Phrase;

typedef struct ChewingOutput {
  /**
   * The content of edit buffer
   */
  char preeditBuf[MAX_PHONE_SEQ_UTF8_BUF];
  /**
   * The length of edit buffer
   */
  int chiSymbolBufLen;
  /**
   * The current position of the cursor
   */
  long chiSymbolCursor;
  long pointStart;
  long pointEnd;
  char bopomofoBuf[MAX_BOPOMOFO_UTF8_BUF];
  IntervalType dispInterval[MAX_INTERVAL];
  int nDispInterval;
  int dispBrkpt[MAX_PHONE_SEQ_BUF];
  char commitBuf[MAX_PHONE_SEQ_UTF8_BUF];
  int commitBufLen;
  struct ChoiceInfo *pci;
  int bChiSym;
  int selKey[MAX_SELKEY];
  int keystrokeRtn;
} ChewingOutput;

typedef struct ChewingContext {
  struct ChewingData *data;
  struct ChewingOutput *output;
  int cand_no;
  int it_no;
  int kb_no;
} ChewingContext;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

extern int toPreeditBufIndex(struct ChewingData *pgdata, int pos);

extern int HaninSymbolInput(struct ChewingData *pgdata);

struct SyllableEditorWithKeymap *NewPhoneticEditor(enum KeyboardLayoutCompat kb_type);

void FreePhoneticEditor(struct SyllableEditorWithKeymap *editor_keymap);

enum KeyBehavior BopomofoPhoInput(struct ChewingData *pgdata, int32_t key);

void BopomofoPhoInx(const struct BopomofoData *bopomofo_data, int32_t *pho_inx);

void BopomofoPhoInxAlt(const struct BopomofoData *bopomofo_data, int32_t *pho_inx);

void BopomofoKeyseq(const struct BopomofoData *bopomofo_data, char *key_seq);

uint16_t BopomofoSyllableIndex(const struct BopomofoData *bopomofo_data);

uint16_t BopomofoSyllableIndexAlt(const struct BopomofoData *bopomofo_data);

uint16_t BopomofoRemoveLast(struct BopomofoData *bopomofo_data);

uint16_t BopomofoRemoveAll(struct BopomofoData *bopomofo_data);

int BopomofoKbType(const struct BopomofoData *bopomofo_data);

uint16_t BopomofoIsEntering(const struct BopomofoData *bopomofo_data);

bool InitPinyin(struct ChewingData *_pgdata, char *_path);

void TerminatePinyin(struct ChewingData *_pgdata);

int InitTree(struct ChewingData *pgdata, const char *_prefix);

void TerminateTree(struct ChewingData *pgdata);

void Phrasing(struct ChewingData *pgdata, bool _all_phrasing);

bool IsIntersect(IntervalType in1, IntervalType in2);

int InitDict(struct ChewingData *pgdata, const char *prefix);

void TerminateDict(struct ChewingData *pgdata);

bool GetCharFirst(struct ChewingData *pgdata, struct Phrase *phrase, uint16_t syllable_u16);

void GetPhraseFirst(struct ChewingData *pgdata,
                    struct Phrase *phrase,
                    const struct TreeType *tree_type);

struct TreeType *TreeFindPhrase(struct ChewingData *pgdata,
                                int begin,
                                int end,
                                uint16_t *syllables_u16);

void FreeTreePhrase(struct TreeType *tree_type);

bool GetVocabNext(struct ChewingData *pgdata, struct Phrase *phrase);

uint16_t UintFromPhone(const char *phone);

uint16_t UintFromPhoneInx(const int *ph_inx);

int PhoneFromUint(char *phone, size_t phone_len, uint16_t phone_num);

ptrdiff_t UintArrayFromBopomofo(uint16_t *phone_seq, size_t phone_len, const char *bopomofo_buf);

int GetPhoneLenFromUint(uint16_t phone_num);

int get_search_path(char *path, size_t path_len);

int find_path_by_files(const char *search_path,
                       const char *const *files,
                       uint8_t *output,
                       size_t output_len);

char *GetDefaultUserPhrasePath(void *_data);

void FreeDefaultUserPhrasePath(char *path);

int InitUserphrase(struct ChewingData *pgdata, char *path);

void TerminateUserphrase(struct ChewingData *pgdata);

const struct UserPhraseData *UserGetPhraseFirst(struct ChewingData *pgdata,
                                                uint16_t *syllables_u16_ptr);

const struct UserPhraseData *UserGetPhraseNext(struct ChewingData *pgdata,
                                               uint16_t *_syllables_u16_ptr);

void UserGetPhraseEnd(struct ChewingData *pgdata, uint16_t *_syllables_u16_ptr);

uint8_t UserUpdatePhrase(struct ChewingData *pgdata,
                         uint16_t *syllables_u16_ptr,
                         char *phrase_str_ptr);

bool UserRemovePhrase(struct ChewingData *pgdata,
                      uint16_t *syllables_u16_ptr,
                      char *phrase_str_ptr);

void IncreaseLifeTime(struct ChewingData *pgdata);

void UserUpdatePhraseBegin(struct ChewingData *_pgdata);

void UserUpdatePhraseEnd(struct ChewingData *_pgdata);

void *UserEnumeratePhrase(const struct UserphraseDbAndEstimate *ue);

bool UserEnumerateHasNext(void *iter_ptr, unsigned int *phrase_len_ptr, unsigned int *bopomofo_len);

int UserEnumerateGet(void *iter_ptr,
                     char *phrase_buf,
                     const unsigned int *_phrase_len_ptr,
                     char *bopomofo_buf,
                     const unsigned int *_bopomofo_len);

int ueStrLen(const char *str);

int ueBytesFromChar(unsigned char b);

int ueStrNBytes(const char *str, int n);

int ueStrNCpy(char *dest, const char *src, size_t n, int end);

char *ueStrSeek(char *src, size_t n);

const char *ueConstStrSeek(const char *src, size_t n);

const char *ueStrStr(const char *str, size_t _lstr, const char *substr, size_t _lsub);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif /* chewing_internal_bindings_h */
