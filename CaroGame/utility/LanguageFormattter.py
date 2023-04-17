import sys
import functools

help = '''
    This script is used to format the language files.
    Usage:
        --help  :   Print this message
        --create:   Create a new language file template.
        file names: Format files
            Ex: python3 formatter.py en.txt
'''

key_word_list = ['[LANGUAGE]', '[LANG_SELECT]', 'ABOUT_DESC', 'ABOUT_SHORTCUT', 'ABOUT_TITLE', 'ABOUT_US_TITLE', 'ANY_KEY_CONTINUE', 'APPLY_FAILED', 'APPLY_KEY_TITLE', 'APPLY_SUCCESSFULLY', 'ARE_YOU_SURE', 'BACK_TITLE', 'BG_MUSIC_TITLE', 'CHANGE_INPUT_LABEL', 'CUR_DIFFICULTY', 'CUR_GAME_MODE', 'CUR_GAME_TYPE', 'CUR_MOVE_COUNT', 'CUR_NAME', 'CUR_SCORE', 'CUR_TIME', 'DELETE_KEY_TITLE', 'DELETE_NOTICE_TITLE', 'DRAW_TEXT', 'EMPTY_SAVE_DESC', 'ENABLE_MUSIC_Q', 'ENABLE_SOUND_EFFECT_Q', 'END_SCREEN_TITLE', 'EXIT_CONFIRM_TITLE', 'EXIT_DESC', 'EXIT_SHORTCUT', 'EXIT_TITLE', 'FOUR_WARNING_TITLE', 'GAME_STATUS_TITLE', 'GHOST_SHORTCUT', 'GHOST_TITLE', 'GROUP_TITLE', 'HELP_1_TITLE', 'HELP_2_TITLE', 'HELP_3-1_TITLE', 'HELP_3_TITLE', 'HELP_4-1_TITLE', 'HELP_4-2_TITLE', 'HELP_4_TITLE', 'HELP_5_TITLE', 'HELP_6-1_TITLE', 'HELP_6_TITLE', 'HELP_7-1_TITLE', 'HELP_7-2_TITLE', 'HELP_7-3_TITLE', 'HELP_8-1_TITLE', 'HELP_8-2_TITLE', 'HELP_8-3_TITLE', 'HELP_8-4_TITLE', 'HELP_8-5_TITLE', 'HINT_OPTION_TITLE', 'HINT_OPTION_TITLE_OFF', 'HINT_OPTION_TITLE_ON', 'HINT_SHORTCUT', 'INSTRUCTOR_TITLE', 'LABEL_AI_DIFFICULTY', 'LABEL_GAME_MODE', 'LABEL_GAME_TYPE', 'LABEL_PAUSE', 'LABEL_PLAYER_NAME_ONE', 'LABEL_PLAYER_NAME_TWO', 'LABEL_PLAY_AGAIN', 'LABEL_RUSH_TIME', 'LABEL_SAVE_REPLAY', 'LOAD_DESC', 'LOAD_FAILED_TITLE', 'LOAD_MENU_TITLE', 'LOAD_SHORTCUT', 'LOAD_TITLE', 'MAIN_MENU_DESC', 'MAIN_MENU_SHORTCUT', 'MAIN_MENU_TITLE', 'MAX_NAME_LENGTH_NOTICE', 'MOVE_HISTORY_TITLE', 'MOVE_SHORTCUT', 'MOVE_TEXT', 'NAMING_FIELD_TITLE', 'NAVIGATE_BACK_KEY_SHORTCUT', 'NAVIGATE_BACK_KEY_TITLE',
                 'NAVIGATION_KEYS_TITLE', 'NEW_GAME_DESC', 'NEW_GAME_SHORTCUT', 'NEW_GAME_TITLE', 'NO_TITLE', 'NO_TITLE_SHORTCUT', 'OFF_TITLE', 'ON_TITLE', 'OPEN_SOURCE_CODE_LINK_TITLE', 'OPTION_1', 'OPTION_15', 'OPTION_15_SHORTCUT', 'OPTION_1_SHORTCUT', 'OPTION_5', 'OPTION_5_SHORTCUT', 'OPTION_AI_EASY', 'OPTION_AI_EASY_SHORTCUT', 'OPTION_AI_HARD', 'OPTION_AI_HARD_SHORTCUT', 'OPTION_AI_NORMAL', 'OPTION_AI_NORMAL_SHORTCUT', 'OPTION_MODE_PVE', 'OPTION_MODE_PVP', 'OPTION_NO', 'OPTION_NULL', 'OPTION_TYPE_NORMAL', 'OPTION_TYPE_RUSH', 'OPTION_YES', 'OVERWRITE_NOTICE_TITLE', 'PAUSE_SHORTCUT', 'PAUSE_TITLE', 'PLACE_SHORTCUT', 'PLACE_TITLE', 'PLAYED_TEXT', 'PLAYER_NAME_LABEL', 'PLAYER_NAME_ONE_LABEL', 'PLAYER_NAME_TWO_LABEL', 'PLAYER_TEXT', 'PLAYER_TIME', 'PLAYER_TIME_TEXT', 'PVE_SHORTCUT', 'PVP_SHORTCUT', 'REPLAY_DESC', 'REPLAY_LOAD_MENU_TITLE', 'REPLAY_SAVE_MENU_TITLE', 'REPLAY_SEEK_TITLE', 'REPLAY_SHORTCUT', 'REPLAY_TITLE', 'SAVE_DESC', 'SAVE_FAILED_TITLE', 'SAVE_MENU_TITLE', 'SAVE_SHORTCUT', 'SAVE_SUCCESS_TITLE', 'SAVE_TITLE', 'SCROLL_SHORTCUT', 'SCROLL_TITLE', 'SEARCH_FIELD_TITLE', 'SEARCH_KEY_TITLE', 'SELECT_AVATAR_TITLE', 'SELECT_KEY_TITLE', 'SETTINGS_DESC', 'SETTINGS_SHORTCUT', 'SETTINGS_TITLE', 'SOUND_EFFECT_TITLE', 'SPACE_KEY_CONTINUE', 'STRING_INPUT_DONE_LABEL', 'THEME_SELECT_TITLE', 'TIME_OUT', 'TUTORIAL_DESC', 'TUTORIAL_Q', 'TUTORIAL_SHORTCUT', 'TUTORIAL_TITLE', 'TYPE_NORMAL_SHORTCUT', 'TYPE_RUSH_SHORTCUT', 'UNDO_OPTION_TITLE', 'UNDO_OPTION_TITLE_OFF', 'UNDO_OPTION_TITLE_ON', 'UNDO_SHORTCUT', 'WIN_TEXT', 'WIN_TIME_TEXT', 'YES_TITLE', 'YES_TITLE_SHORTCUT']


def basiccmp(str1, str2):
    if str1 == str2:
        return 0
    else:
        return 1 if str1 > str2 else -1


def sortfunc(item1, item2):
    if item1[0] == '[' and item2[0] == '[':
        return basiccmp(item1, item2)
    elif item1[0] == '[':
        return -1
    elif item2[0] == '[':
        return 1
    else:
        return basiccmp(item1, item2)


def formatter():
    files_formatted = []
    for file in sys.argv[1:]:
        try:
            f = open(file, encoding='utf-8', mode='r')
        except:
            continue

        tmp = [_.split(sep='=') for _ in filter(
            lambda x: len(x) > 0, [line.strip() for line in f])]
        f.close()
        for i in range(len(tmp)):
            tmp[i] = [_.strip() for _ in tmp[i]]

        mmax = (max([len(_[0]) for _ in tmp]) // 4) * 4 + 4
        check_list = [_ for _ in key_word_list]
        for index, i in enumerate(tmp):
            if i[0] not in key_word_list:
                print(
                    f"Warning:\nFile: {file}, at line: {index+1}, label: {i[0]} does not exist in the game.")
                continue
            if i[0] in check_list:
                check_list.remove(i[0])
            else:
                print(
                    f"Warning:\nFile: {file}, at line: {index+1}, label: {i[0]} appeared more than once.")

        if (len(check_list)):
            print(f"Warning:\nFile: {file}, you are missing these:")
            for i in check_list:
                print('    ' + i)
            print()

        f = open(file, mode='w', encoding='utf-8')
        f.writelines(sorted(["=".join([_[0].ljust(mmax), "    " + _[1]]) +
                     '\n' for _ in tmp], key=functools.cmp_to_key(sortfunc)))
        f.close()
        files_formatted.append(file)

    print(f"Formatted successful: {', '.join(files_formatted)}")


if __name__ == '__main__':
    if '--create' in sys.argv:
        filename = input("Enter the file name: ")
        f = open(filename, mode='w', encoding='utf-8')
        mmax = (max([len(_) for _ in key_word_list]) // 4) * 4 + 4
        f.write('=\n'.join([_.ljust(mmax) for _ in key_word_list]))
    elif '--help' in sys.argv or len(sys.argv) == 1:
        print(help)
    else:
        formatter()
