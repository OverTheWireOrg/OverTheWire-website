PHP_FUNCTION(dovuln)
{
        zval **p_str, **p_len;
        char *str, *smashme;
        int argc = ZEND_NUM_ARGS(), len = 42, strlen;
        
        if (argc < 2 || argc > 3 || zend_get_parameters_ex(argc, &p_str, &p_len) == FAILURE) {
             WRONG_PARAM_COUNT;
        }

        convert_to_string_ex(p_str);
        convert_to_long_ex(p_len);
        len = Z_LVAL_PP(p_len);
        str = Z_STRVAL_PP(p_str);
        strlen = Z_STRLEN_PP(p_str);
        smashme = emalloc(len);
        memcpy(smashme, str, strlen); //xxx
}
