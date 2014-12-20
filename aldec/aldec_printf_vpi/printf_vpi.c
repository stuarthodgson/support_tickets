
#include <stddef.h>
#include <stdio.h>
#include <vpi_user.h>

static void print_err(void)
{
    s_vpi_error_info info;
    vpi_chk_error(&info);
    vpi_printf("ERROR: %s (%d): %s\n", info.file, info.code, info.message);
}

static int32_t just_do_a_print(p_cb_data cb_data)
{
    printf("This should be printed\n");
    return 0;
}

static void register_initial_callback(void)
{
    s_cb_data cb_data_s;

    cb_data_s.reason    = cbStartOfSimulation;
    cb_data_s.cb_rtn    = just_do_a_print;
    cb_data_s.obj       = NULL;
    cb_data_s.time      = NULL;
    cb_data_s.value     = NULL;
    cb_data_s.user_data = NULL;
    
    vpiHandle new_hdl = vpi_register_cb(&cb_data_s);
    if (!new_hdl) {
        vpi_printf("**** ERROR: Could not register the callback\n");
        vpi_control(vpiFinish, 0);
    }
}

void (*vlog_startup_routines[])(void) = {
    register_initial_callback,
    0
};


