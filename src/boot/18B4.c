#include "common.h"

#define INCLUDE_ASM_TARGET boot

INCLUDE_ASM("18B4", func_800110B4);

INCLUDE_ASM("18B4", func_800110C0);

INCLUDE_ASM("18B4", func_800111E4);

void func_80011274(void) {
    func_80033E34(D_80048D1C, D_80048D20, (u32*)0x800E0000, 0);

    while (1) {
        if (func_80034B44() == 0) {
            break;
        }
    }

    func_80033E34(D_80048D14, D_80048D18, (u32*)0x800A0000, 0);

    while (1) {
        if (func_80034B44() == 0) {
            break;
        }
    }

    func_80029818((u32*)0x800A0000, (u32*)0x800E0000);
}

INCLUDE_ASM("18B4", func_800112E8);

INCLUDE_ASM("18B4", func_8001146C);

INCLUDE_ASM("18B4", func_8001155C);

INCLUDE_ASM("18B4", func_8001171C);

INCLUDE_ASM("18B4", func_80011784);

INCLUDE_ASM("18B4", func_80011860);

void func_80011920(void) {
    D_800965E8 = 0;
    D_80071A5C = 0;
}

INCLUDE_ASM("18B4", func_80011938);

INCLUDE_ASM("18B4", func_800119E4);

INCLUDE_ASM("18B4", func_80011AEC);

// something is out of order
#ifdef NON_MATCHING
void func_80011BB4(void) {
    D_8009D588 = 1;
    D_8009D274 = 0;
    D_8009D278 = 1;
    D_8009D27A = 0x74;
    D_8009D27E = 0;
    D_8009D280 = 0;
    D_8009D282 = 0;
    D_8009D284 = 0;
    D_8009D285 = 0;
    D_8009D286 = 0;
}
#else
INCLUDE_ASM("18B4", func_80011BB4);
#endif

INCLUDE_ASM("18B4", func_80011C1C);

INCLUDE_ASM("18B4", func_80012840);

INCLUDE_ASM("18B4", func_800128B8);

INCLUDE_ASM("18B4", func_800129D0);

INCLUDE_ASM("18B4", func_80012A8C);

INCLUDE_ASM("18B4", func_80012DB0);

INCLUDE_ASM("18B4", func_800131B8);

INCLUDE_ASM("18B4", func_800134F4);

INCLUDE_ASM("18B4", func_80013564);

INCLUDE_ASM("18B4", func_800135C0);

INCLUDE_ASM("18B4", func_80013624);

INCLUDE_ASM("18B4", func_80013800);

INCLUDE_ASM("18B4", func_800138EC);

INCLUDE_ASM("18B4", func_80013C9C);

void func_800140A4(void) {
    D_8019DAA0++;
    if ((D_8019DAA0 & 1) == 0) {
        func_8004433C(D_8019D5E8);
        func_80013C9C();
    }
}

INCLUDE_ASM("18B4", func_800140F4);

INCLUDE_ASM("18B4", func_800144D8);

void func_800144F0(s32 arg0) {
    func_80033DAC(arg0, 0);
}

// looks like it is generating safety code for the circumstance of arg0 < 0??
#ifdef NON_MATCHING
void func_80014510(s32 arg0) {
    func_800144F0(D_80048D84[arg0]);
}
#else
INCLUDE_ASM("18B4", func_80014510);
#endif

void func_80014540(void) {
    func_80033E34(D_80071744, D_80095DD8, D_800722C8, 0);
}

INCLUDE_ASM("18B4", func_80014578);

INCLUDE_ASM("18B4", func_800145BC);

void func_80014608(void) {
}

void func_80014610(void) {
    u8 sp10[0x800];

    func_80033E34(0x266, 0x800, &sp10, 0);
    func_800145BC(0);
    func_80014A00(D_80048D84, &sp10, 0x50);
}

INCLUDE_ASM("18B4", func_80014658);

INCLUDE_ASM("18B4", func_800146A4);

INCLUDE_ASM("18B4", func_80014750);

INCLUDE_ASM("18B4", func_80014804);

INCLUDE_ASM("18B4", func_800148A0);

INCLUDE_ASM("18B4", func_800148B4);

INCLUDE_ASM("18B4", func_80014934);

INCLUDE_ASM("18B4", func_80014980);

INCLUDE_ASM("18B4", func_800149E0);

INCLUDE_ASM("18B4", func_80014A00);

INCLUDE_ASM("18B4", func_80014A38);

INCLUDE_ASM("18B4", func_80014A58);

INCLUDE_ASM("18B4", func_80014A84);

INCLUDE_ASM("18B4", func_80014B08);

INCLUDE_ASM("18B4", func_80014B54);

INCLUDE_ASM("18B4", func_80014B70);

INCLUDE_ASM("18B4", func_80014BA8);

INCLUDE_ASM("18B4", func_80014BE4);

INCLUDE_ASM("18B4", func_80014C44);

INCLUDE_ASM("18B4", func_80014C70);

INCLUDE_ASM("18B4", func_80014C80);

INCLUDE_ASM("18B4", func_80014CBC);

INCLUDE_ASM("18B4", func_80014D58);

INCLUDE_ASM("18B4", func_80014D9C);

INCLUDE_ASM("18B4", func_80014DD0);

INCLUDE_ASM("18B4", func_80014E0C);

INCLUDE_ASM("18B4", func_80014E74);

INCLUDE_ASM("18B4", func_800150E4);

INCLUDE_ASM("18B4", func_800151F4);

INCLUDE_ASM("18B4", func_8001521C);

INCLUDE_ASM("18B4", func_80015248);

INCLUDE_ASM("18B4", func_800155A4);

INCLUDE_ASM("18B4", func_800155B0);

INCLUDE_ASM("18B4", func_80015654);

INCLUDE_ASM("18B4", func_80015668);

INCLUDE_ASM("18B4", func_800159B0);

INCLUDE_ASM("18B4", func_80015AFC);

INCLUDE_ASM("18B4", func_80015B44);

INCLUDE_ASM("18B4", func_80015B50);

INCLUDE_ASM("18B4", func_80015B88);

INCLUDE_ASM("18B4", func_80015BC0);

INCLUDE_ASM("18B4", func_80015C3C);

INCLUDE_ASM("18B4", func_80015CA0);

INCLUDE_ASM("18B4", func_80015D14);

INCLUDE_ASM("18B4", func_80015D64);

INCLUDE_ASM("18B4", func_80016320);

INCLUDE_ASM("18B4", func_80016340);

INCLUDE_ASM("18B4", func_800166C0);

INCLUDE_ASM("18B4", func_80016808);

INCLUDE_ASM("18B4", func_800169B8);

INCLUDE_ASM("18B4", func_80016F90);

INCLUDE_ASM("18B4", func_8001708C);

INCLUDE_ASM("18B4", func_80017108);

INCLUDE_ASM("18B4", func_80017238);

INCLUDE_ASM("18B4", func_8001726C);

INCLUDE_ASM("18B4", func_80017678);

INCLUDE_ASM("18B4", func_8001786C);

INCLUDE_ASM("18B4", func_80017E68);

INCLUDE_ASM("18B4", func_80017F38);

INCLUDE_ASM("18B4", func_80018028);

INCLUDE_ASM("18B4", func_80018220);

INCLUDE_ASM("18B4", func_800182FC);

INCLUDE_ASM("18B4", func_80018390);

INCLUDE_ASM("18B4", func_8001840C);

INCLUDE_ASM("18B4", func_800184C0);

INCLUDE_ASM("18B4", func_800185A8);

INCLUDE_ASM("18B4", func_80018630);

INCLUDE_ASM("18B4", func_80018834);

INCLUDE_ASM("18B4", func_80018934);

INCLUDE_ASM("18B4", func_80018A04);

INCLUDE_ASM("18B4", func_80018AB0);

INCLUDE_ASM("18B4", func_80018B14);

INCLUDE_ASM("18B4", func_80018BB8);

INCLUDE_ASM("18B4", func_80018C94);

INCLUDE_ASM("18B4", func_80018D4C);

INCLUDE_ASM("18B4", func_80018E18);

INCLUDE_ASM("18B4", func_80018E90);

INCLUDE_ASM("18B4", func_80018ECC);

INCLUDE_ASM("18B4", func_80018FC0);

INCLUDE_ASM("18B4", func_80019064);

INCLUDE_ASM("18B4", func_800190E8);

INCLUDE_ASM("18B4", func_800191A0);

INCLUDE_ASM("18B4", func_80019254);

INCLUDE_ASM("18B4", func_80019338);

INCLUDE_ASM("18B4", func_8001937C);

INCLUDE_ASM("18B4", func_800193F4);

INCLUDE_ASM("18B4", func_80019440);

INCLUDE_ASM("18B4", func_800194BC);

INCLUDE_ASM("18B4", func_80019544);

INCLUDE_ASM("18B4", func_80019608);

INCLUDE_ASM("18B4", func_8001964C);

INCLUDE_ASM("18B4", func_80019690);

INCLUDE_ASM("18B4", func_800197B8);

INCLUDE_ASM("18B4", func_80019978);

INCLUDE_ASM("18B4", func_80019D1C);

INCLUDE_ASM("18B4", func_80019D74);

INCLUDE_ASM("18B4", func_80019DA0);

INCLUDE_ASM("18B4", func_80019E4C);

INCLUDE_ASM("18B4", func_80019E84);

INCLUDE_ASM("18B4", func_80019F90);

INCLUDE_ASM("18B4", func_8001A174);

INCLUDE_ASM("18B4", func_8001A1C8);

INCLUDE_ASM("18B4", func_8001A280);

INCLUDE_ASM("18B4", func_8001A384);

INCLUDE_ASM("18B4", func_8001A3B8);

INCLUDE_ASM("18B4", func_8001A440);

INCLUDE_ASM("18B4", func_8001A4A8);

INCLUDE_ASM("18B4", func_8001A518);

INCLUDE_ASM("18B4", func_8001A5B4);

INCLUDE_ASM("18B4", func_8001A684);

INCLUDE_ASM("18B4", func_8001A780);

INCLUDE_ASM("18B4", func_8001A874);

INCLUDE_ASM("18B4", func_8001A980);

INCLUDE_ASM("18B4", func_8001A9CC);

INCLUDE_ASM("18B4", func_8001AB1C);

INCLUDE_ASM("18B4", func_8001AC9C);

INCLUDE_ASM("18B4", func_8001AE08);

INCLUDE_ASM("18B4", func_8001AEE4);

INCLUDE_ASM("18B4", func_8001B4A0);

INCLUDE_ASM("18B4", func_8001B570);

INCLUDE_ASM("18B4", func_8001B5E4);

INCLUDE_ASM("18B4", func_8001B704);

INCLUDE_ASM("18B4", func_8001B834);

INCLUDE_ASM("18B4", func_8001B8A8);

INCLUDE_ASM("18B4", func_8001B944);

INCLUDE_ASM("18B4", func_8001BA54);

INCLUDE_ASM("18B4", func_8001BB30);

INCLUDE_ASM("18B4", func_8001BC18);

INCLUDE_ASM("18B4", func_8001BCE8);

INCLUDE_ASM("18B4", func_8001BD50);

INCLUDE_ASM("18B4", func_8001BDB0);

INCLUDE_ASM("18B4", func_8001C0EC);

void func_8001C3C4(void) {
}

INCLUDE_ASM("18B4", func_8001C3CC);

INCLUDE_ASM("18B4", func_8001C434);

INCLUDE_ASM("18B4", func_8001C484);

INCLUDE_ASM("18B4", func_8001C498);

INCLUDE_ASM("18B4", func_8001C4E8);

INCLUDE_ASM("18B4", func_8001C58C);

INCLUDE_ASM("18B4", func_8001C5BC);

INCLUDE_ASM("18B4", func_8001C788);

INCLUDE_ASM("18B4", func_8001C808);

INCLUDE_ASM("18B4", func_8001C8D4);

INCLUDE_ASM("18B4", func_8001C980);

INCLUDE_ASM("18B4", func_8001CB48);

INCLUDE_ASM("18B4", func_8001CDA4);

INCLUDE_ASM("18B4", func_8001CF3C);

INCLUDE_ASM("18B4", func_8001D180);

INCLUDE_ASM("18B4", func_8001D3C0);

INCLUDE_ASM("18B4", func_8001D47C);

INCLUDE_ASM("18B4", func_8001D56C);

INCLUDE_ASM("18B4", func_8001D6A8);

INCLUDE_ASM("18B4", func_8001DE0C);

INCLUDE_ASM("18B4", func_8001DE24);

INCLUDE_ASM("18B4", func_8001DE40);

INCLUDE_ASM("18B4", func_8001DE70);

INCLUDE_ASM("18B4", func_8001DEB0);

INCLUDE_ASM("18B4", func_8001DEF0);

INCLUDE_ASM("18B4", func_8001DF24);

INCLUDE_ASM("18B4", func_8001E040);

INCLUDE_ASM("18B4", func_8001EB2C);

INCLUDE_ASM("18B4", func_8001EC70);

INCLUDE_ASM("18B4", func_8001EF84);

INCLUDE_ASM("18B4", func_8001F1BC);

void func_8001F6AC(void) {
}

INCLUDE_ASM("18B4", func_8001F6B4);

INCLUDE_ASM("18B4", func_8001F6C0);

INCLUDE_ASM("18B4", func_8001F6E4);

INCLUDE_ASM("18B4", func_8001F710);

INCLUDE_ASM("18B4", func_8001FA28);

INCLUDE_ASM("18B4", func_8001FA68);

INCLUDE_ASM("18B4", func_8001FAAC);

void func_8001FAF0(void) {
}

INCLUDE_ASM("18B4", func_8001FAF8);

INCLUDE_ASM("18B4", func_8001FBAC);

INCLUDE_ASM("18B4", func_8001FCDC);

INCLUDE_ASM("18B4", func_8001FE6C);

INCLUDE_ASM("18B4", func_8001FF50);

INCLUDE_ASM("18B4", func_8001FF8C);

INCLUDE_ASM("18B4", func_8001FFD4);

INCLUDE_ASM("18B4", func_8002001C);

INCLUDE_ASM("18B4", func_80020058);

INCLUDE_ASM("18B4", func_800206E4);

INCLUDE_ASM("18B4", func_80020B68);

INCLUDE_ASM("18B4", func_80021044);

INCLUDE_ASM("18B4", func_800211B8);

INCLUDE_ASM("18B4", func_800211C4);

INCLUDE_ASM("18B4", func_8002120C);

INCLUDE_ASM("18B4", func_80021258);

INCLUDE_ASM("18B4", func_80021280);

INCLUDE_ASM("18B4", func_800212A8);

INCLUDE_ASM("18B4", func_80021BAC);

INCLUDE_ASM("18B4", func_80021C4C);

INCLUDE_ASM("18B4", func_80021D5C);

INCLUDE_ASM("18B4", func_80021E70);

INCLUDE_ASM("18B4", func_80021F58);

INCLUDE_ASM("18B4", func_80022B5C);

INCLUDE_ASM("18B4", func_80022DE4);

INCLUDE_ASM("18B4", func_80022FE0);

INCLUDE_ASM("18B4", func_80023050);

INCLUDE_ASM("18B4", func_8002305C);

INCLUDE_ASM("18B4", func_800230C4);

INCLUDE_ASM("18B4", func_8002368C);

INCLUDE_ASM("18B4", func_80023788);

INCLUDE_ASM("18B4", func_8002382C);

INCLUDE_ASM("18B4", func_80023940);

INCLUDE_ASM("18B4", func_80023AC4);

INCLUDE_ASM("18B4", func_80023AD4);

INCLUDE_ASM("18B4", func_80024A04);

INCLUDE_ASM("18B4", func_80024A3C);

INCLUDE_ASM("18B4", func_80024D88);

INCLUDE_ASM("18B4", func_80024DD4);

INCLUDE_ASM("18B4", func_80024E18);

INCLUDE_ASM("18B4", func_80024E5C);

INCLUDE_ASM("18B4", func_80024E94);

INCLUDE_ASM("18B4", func_80024ECC);

INCLUDE_ASM("18B4", func_80024F04);

INCLUDE_ASM("18B4", func_80024F3C);

INCLUDE_ASM("18B4", func_80024F80);

INCLUDE_ASM("18B4", func_80024FC4);

INCLUDE_ASM("18B4", func_80025008);

INCLUDE_ASM("18B4", func_80025040);

INCLUDE_ASM("18B4", func_800250B4);

INCLUDE_ASM("18B4", func_800250EC);

INCLUDE_ASM("18B4", func_80025130);

INCLUDE_ASM("18B4", func_80025174);

INCLUDE_ASM("18B4", func_80025288);

INCLUDE_ASM("18B4", func_80025310);

INCLUDE_ASM("18B4", func_80025360);

INCLUDE_ASM("18B4", func_80025380);

INCLUDE_ASM("18B4", func_8002542C);

INCLUDE_ASM("18B4", func_800254D8);

INCLUDE_ASM("18B4", func_800254E4);

INCLUDE_ASM("18B4", func_80025514);

void func_80025648(void) {
}

void func_80025650(void) {
}

INCLUDE_ASM("18B4", func_80025658);

INCLUDE_ASM("18B4", func_80025668);

INCLUDE_ASM("18B4", func_800256DC);

INCLUDE_ASM("18B4", func_80025758);

INCLUDE_ASM("18B4", func_80025774);

INCLUDE_ASM("18B4", func_80025788);

void func_800257C4(void) {
}

INCLUDE_ASM("18B4", func_800257CC);

INCLUDE_ASM("18B4", func_80025800);

INCLUDE_ASM("18B4", func_800258BC);

INCLUDE_ASM("18B4", func_80025988);

INCLUDE_ASM("18B4", func_80025A44);

INCLUDE_ASM("18B4", func_80025B10);

INCLUDE_ASM("18B4", func_80025B48);

INCLUDE_ASM("18B4", func_80025B7C);

INCLUDE_ASM("18B4", func_80025B8C);

INCLUDE_ASM("18B4", func_80025BD0);

INCLUDE_ASM("18B4", func_80025C14);

INCLUDE_ASM("18B4", func_80025C54);

INCLUDE_ASM("18B4", func_80025C94);

INCLUDE_ASM("18B4", func_80025CD4);

INCLUDE_ASM("18B4", func_80025D14);

INCLUDE_ASM("18B4", func_80025DF8);

INCLUDE_ASM("18B4", func_80025ED4);

void func_80026034(void) {
}

INCLUDE_ASM("18B4", func_8002603C);

INCLUDE_ASM("18B4", func_80026090);

INCLUDE_ASM("18B4", func_800260DC);

INCLUDE_ASM("18B4", func_80026258);

INCLUDE_ASM("18B4", func_800262D8);

INCLUDE_ASM("18B4", func_80026408);

INCLUDE_ASM("18B4", func_80026448);

INCLUDE_ASM("18B4", func_800264A8);

INCLUDE_ASM("18B4", func_800269C0);

INCLUDE_ASM("18B4", func_800269D0);

INCLUDE_ASM("18B4", func_800269E8);

INCLUDE_ASM("18B4", func_80026A00);

INCLUDE_ASM("18B4", func_80026A0C);

INCLUDE_ASM("18B4", func_80026A20);

INCLUDE_ASM("18B4", func_80026A34);

INCLUDE_ASM("18B4", func_80026A94);

void func_80026B5C(void) {
}

INCLUDE_ASM("18B4", func_80026B64);

INCLUDE_ASM("18B4", func_80026B70);

INCLUDE_ASM("18B4", func_80026C5C);

INCLUDE_ASM("18B4", func_80026F44);

INCLUDE_ASM("18B4", func_8002708C);

INCLUDE_ASM("18B4", func_80027354);

INCLUDE_ASM("18B4", func_80027408);

INCLUDE_ASM("18B4", func_80027990);

INCLUDE_ASM("18B4", func_80027B84);

INCLUDE_ASM("18B4", func_80028030);

INCLUDE_ASM("18B4", func_80028484);

INCLUDE_ASM("18B4", func_800285AC);

INCLUDE_ASM("18B4", func_80028930);

INCLUDE_ASM("18B4", func_80028CA0);

INCLUDE_ASM("18B4", func_80028E00);

INCLUDE_ASM("18B4", func_80029114);

INCLUDE_ASM("18B4", func_800293D0);

INCLUDE_ASM("18B4", func_800293F4);

INCLUDE_ASM("18B4", func_80029424);

INCLUDE_ASM("18B4", func_80029464);

INCLUDE_ASM("18B4", func_800294A4);

INCLUDE_ASM("18B4", func_800294BC);

INCLUDE_ASM("18B4", func_800297A4);

INCLUDE_ASM("18B4", func_80029818);

INCLUDE_ASM("18B4", func_8002988C);

INCLUDE_ASM("18B4", func_80029998);

INCLUDE_ASM("18B4", func_800299C8);

INCLUDE_ASM("18B4", func_80029A50);

INCLUDE_ASM("18B4", func_80029AF0);

INCLUDE_ASM("18B4", func_80029B78);

INCLUDE_ASM("18B4", func_80029BAC);

INCLUDE_ASM("18B4", func_80029C48);

INCLUDE_ASM("18B4", func_80029E98);

INCLUDE_ASM("18B4", func_80029F44);

INCLUDE_ASM("18B4", func_8002A094);

INCLUDE_ASM("18B4", func_8002A28C);

INCLUDE_ASM("18B4", func_8002A43C);

INCLUDE_ASM("18B4", func_8002A510);

INCLUDE_ASM("18B4", func_8002A6C4);

INCLUDE_ASM("18B4", func_8002A748);

INCLUDE_ASM("18B4", func_8002A798);

INCLUDE_ASM("18B4", func_8002A7E8);

INCLUDE_ASM("18B4", func_8002A958);

INCLUDE_ASM("18B4", func_8002AABC);

INCLUDE_ASM("18B4", func_8002AFB8);

INCLUDE_ASM("18B4", func_8002B1A8);

INCLUDE_ASM("18B4", func_8002B1F8);

INCLUDE_ASM("18B4", func_8002B2F8);

INCLUDE_ASM("18B4", func_8002B3B4);

INCLUDE_ASM("18B4", func_8002B5A8);

INCLUDE_ASM("18B4", func_8002B608);

INCLUDE_ASM("18B4", func_8002B668);

INCLUDE_ASM("18B4", func_8002B6AC);

INCLUDE_ASM("18B4", func_8002B730);

INCLUDE_ASM("18B4", func_8002B7E0);

INCLUDE_ASM("18B4", func_8002B8B4);

INCLUDE_ASM("18B4", func_8002B904);

INCLUDE_ASM("18B4", func_8002B958);

INCLUDE_ASM("18B4", func_8002B9AC);

INCLUDE_ASM("18B4", func_8002BA08);

INCLUDE_ASM("18B4", func_8002BA5C);

INCLUDE_ASM("18B4", func_8002BA98);

INCLUDE_ASM("18B4", func_8002BB20);

INCLUDE_ASM("18B4", func_8002BBB4);

INCLUDE_ASM("18B4", func_8002BBEC);

INCLUDE_ASM("18B4", func_8002BC58);

INCLUDE_ASM("18B4", func_8002BCCC);

INCLUDE_ASM("18B4", func_8002BD04);

INCLUDE_ASM("18B4", func_8002BDCC);

INCLUDE_ASM("18B4", func_8002BE2C);

INCLUDE_ASM("18B4", func_8002BE8C);

INCLUDE_ASM("18B4", func_8002BEB4);

INCLUDE_ASM("18B4", func_8002BEDC);

INCLUDE_ASM("18B4", func_8002BF04);

INCLUDE_ASM("18B4", func_8002BF2C);

INCLUDE_ASM("18B4", func_8002BF54);

INCLUDE_ASM("18B4", func_8002BF7C);

INCLUDE_ASM("18B4", func_8002BFA4);

INCLUDE_ASM("18B4", func_8002BFCC);

INCLUDE_ASM("18B4", func_8002C004);

INCLUDE_ASM("18B4", func_8002C0CC);

INCLUDE_ASM("18B4", func_8002C12C);

INCLUDE_ASM("18B4", func_8002C18C);

INCLUDE_ASM("18B4", func_8002C1B4);

INCLUDE_ASM("18B4", func_8002C1DC);

INCLUDE_ASM("18B4", func_8002C204);

INCLUDE_ASM("18B4", func_8002C22C);

INCLUDE_ASM("18B4", func_8002C254);

INCLUDE_ASM("18B4", func_8002C27C);

INCLUDE_ASM("18B4", func_8002C2A4);

INCLUDE_ASM("18B4", func_8002C2CC);

INCLUDE_ASM("18B4", func_8002C300);

INCLUDE_ASM("18B4", func_8002C3A8);

INCLUDE_ASM("18B4", func_8002C408);

INCLUDE_ASM("18B4", func_8002C468);

INCLUDE_ASM("18B4", func_8002C490);

INCLUDE_ASM("18B4", func_8002C4B8);

INCLUDE_ASM("18B4", func_8002C4E0);

INCLUDE_ASM("18B4", func_8002C508);

INCLUDE_ASM("18B4", func_8002C530);

INCLUDE_ASM("18B4", func_8002C558);

INCLUDE_ASM("18B4", func_8002C580);

INCLUDE_ASM("18B4", func_8002C5A8);

INCLUDE_ASM("18B4", func_8002C5C8);

INCLUDE_ASM("18B4", func_8002C634);

INCLUDE_ASM("18B4", func_8002C6A8);

INCLUDE_ASM("18B4", func_8002C6C8);

INCLUDE_ASM("18B4", func_8002C734);

INCLUDE_ASM("18B4", func_8002C7A8);

INCLUDE_ASM("18B4", func_8002C7C8);

INCLUDE_ASM("18B4", func_8002C7E8);

INCLUDE_ASM("18B4", func_8002C81C);

INCLUDE_ASM("18B4", func_8002C850);

INCLUDE_ASM("18B4", func_8002C884);

INCLUDE_ASM("18B4", func_8002C8C4);

INCLUDE_ASM("18B4", func_8002C8DC);

INCLUDE_ASM("18B4", func_8002C9E4);

INCLUDE_ASM("18B4", func_8002CA84);

INCLUDE_ASM("18B4", func_8002CB78);

INCLUDE_ASM("18B4", func_8002CC18);

INCLUDE_ASM("18B4", func_8002CC44);

INCLUDE_ASM("18B4", func_8002CCBC);

INCLUDE_ASM("18B4", func_8002CCCC);

INCLUDE_ASM("18B4", func_8002CCDC);

INCLUDE_ASM("18B4", func_8002CDD0);

INCLUDE_ASM("18B4", func_8002CEC0);

INCLUDE_ASM("18B4", func_8002CF1C);

INCLUDE_ASM("18B4", func_8002CF78);

void func_8002CF98(void) {
}

INCLUDE_ASM("18B4", func_8002CFA0);

INCLUDE_ASM("18B4", func_8002CFC0);

INCLUDE_ASM("18B4", func_8002D1E4);

INCLUDE_ASM("18B4", func_8002D2D4);

INCLUDE_ASM("18B4", func_8002D410);

INCLUDE_ASM("18B4", func_8002D4A0);

INCLUDE_ASM("18B4", func_8002D530);

INCLUDE_ASM("18B4", func_8002D668);

INCLUDE_ASM("18B4", func_8002D7A0);

INCLUDE_ASM("18B4", func_8002D8E8);

INCLUDE_ASM("18B4", func_8002DA30);

INCLUDE_ASM("18B4", func_8002DA7C);

INCLUDE_ASM("18B4", func_8002DF88);

INCLUDE_ASM("18B4", func_8002E1A8);

INCLUDE_ASM("18B4", func_8002E23C);

INCLUDE_ASM("18B4", func_8002E428);

INCLUDE_ASM("18B4", func_8002E478);

INCLUDE_ASM("18B4", func_8002E954);

INCLUDE_ASM("18B4", func_8002ED34);

INCLUDE_ASM("18B4", func_8002F24C);

INCLUDE_ASM("18B4", func_8002F738);

INCLUDE_ASM("18B4", func_8002F848);

INCLUDE_ASM("18B4", func_8002FDA0);

INCLUDE_ASM("18B4", func_8002FE48);

INCLUDE_ASM("18B4", func_8002FF4C);

INCLUDE_ASM("18B4", func_80030038);

INCLUDE_ASM("18B4", func_80030148);

INCLUDE_ASM("18B4", func_80030234);

INCLUDE_ASM("18B4", func_80030380);

INCLUDE_ASM("18B4", func_800308D4);

INCLUDE_ASM("18B4", func_80030E7C);

INCLUDE_ASM("18B4", func_80031820);

INCLUDE_ASM("18B4", func_800318BC);

INCLUDE_ASM("18B4", func_80031A70);

INCLUDE_ASM("18B4", func_80031AB0);

INCLUDE_ASM("18B4", func_80031AFC);

INCLUDE_ASM("18B4", func_80031BA0);

INCLUDE_ASM("18B4", func_80031BE4);

INCLUDE_ASM("18B4", func_80031C88);

INCLUDE_ASM("18B4", func_80031CB0);

INCLUDE_ASM("18B4", func_80031CE0);

INCLUDE_ASM("18B4", func_80031D6C);

INCLUDE_ASM("18B4", func_80031E98);

INCLUDE_ASM("18B4", func_80031EEC);

INCLUDE_ASM("18B4", func_80031F30);

INCLUDE_ASM("18B4", func_80031FC0);

INCLUDE_ASM("18B4", func_80031FF0);

INCLUDE_ASM("18B4", func_80032078);

INCLUDE_ASM("18B4", func_80032094);

INCLUDE_ASM("18B4", func_800320AC);

INCLUDE_ASM("18B4", func_800320C4);

INCLUDE_ASM("18B4", func_80032274);

INCLUDE_ASM("18B4", func_800323CC);

INCLUDE_ASM("18B4", func_800324D8);

INCLUDE_ASM("18B4", func_80032500);

INCLUDE_ASM("18B4", func_8003252C);

INCLUDE_ASM("18B4", func_8003257C);

INCLUDE_ASM("18B4", func_800325B8);

INCLUDE_ASM("18B4", func_800325C0);

INCLUDE_ASM("18B4", func_800325E8);

INCLUDE_ASM("18B4", func_80032614);

INCLUDE_ASM("18B4", func_80032718);

INCLUDE_ASM("18B4", func_80032770);

INCLUDE_ASM("18B4", func_800327E0);

INCLUDE_ASM("18B4", func_80032804);

INCLUDE_ASM("18B4", func_800328D4);

INCLUDE_ASM("18B4", func_800328F8);

INCLUDE_ASM("18B4", func_80032968);

INCLUDE_ASM("18B4", func_8003298C);

INCLUDE_ASM("18B4", func_80032A04);

INCLUDE_ASM("18B4", func_80032A28);

INCLUDE_ASM("18B4", func_80032A98);

INCLUDE_ASM("18B4", func_80032ABC);

INCLUDE_ASM("18B4", func_80032B30);

INCLUDE_ASM("18B4", func_80032BB4);

INCLUDE_ASM("18B4", func_80032C20);

INCLUDE_ASM("18B4", func_80032C8C);

INCLUDE_ASM("18B4", func_80032CE8);

INCLUDE_ASM("18B4", func_80032D44);

void func_80032D50(void) {
}

INCLUDE_ASM("18B4", func_80032D58);

void func_80032D64(void) {
}

INCLUDE_ASM("18B4", func_80032D6C);

INCLUDE_ASM("18B4", func_80032E08);

INCLUDE_ASM("18B4", func_80032E6C);

INCLUDE_ASM("18B4", func_80032ED0);

INCLUDE_ASM("18B4", func_80032F34);

INCLUDE_ASM("18B4", func_80032F98);

INCLUDE_ASM("18B4", func_80032FFC);

INCLUDE_ASM("18B4", func_80033060);

INCLUDE_ASM("18B4", func_800330C4);

INCLUDE_ASM("18B4", func_80033128);

INCLUDE_ASM("18B4", func_800331CC);

INCLUDE_ASM("18B4", func_80033224);

INCLUDE_ASM("18B4", func_80033264);

INCLUDE_ASM("18B4", func_800332EC);

INCLUDE_ASM("18B4", func_8003337C);

INCLUDE_ASM("18B4", func_80033420);

INCLUDE_ASM("18B4", func_8003345C);

INCLUDE_ASM("18B4", func_80033488);

INCLUDE_ASM("18B4", func_800334EC);

INCLUDE_ASM("18B4", func_80033534);

INCLUDE_ASM("18B4", func_80033548);

INCLUDE_ASM("18B4", func_80033588);

INCLUDE_ASM("18B4", func_800335CC);

INCLUDE_ASM("18B4", func_800335D8);

INCLUDE_ASM("18B4", func_80033628);

INCLUDE_ASM("18B4", func_8003366C);

INCLUDE_ASM("18B4", func_80033698);

INCLUDE_ASM("18B4", func_800336DC);

INCLUDE_ASM("18B4", func_80033708);

INCLUDE_ASM("18B4", func_80033788);

INCLUDE_ASM("18B4", func_8003379C);

INCLUDE_ASM("18B4", func_800337B0);

INCLUDE_ASM("18B4", func_800337C4);

INCLUDE_ASM("18B4", func_800337D8);

INCLUDE_ASM("18B4", func_80033818);

INCLUDE_ASM("18B4", func_80033894);

INCLUDE_ASM("18B4", func_80033A70);

INCLUDE_ASM("18B4", func_80033A90);

INCLUDE_ASM("18B4", func_80033B70);

INCLUDE_ASM("18B4", func_80033BE0);

INCLUDE_ASM("18B4", func_80033C20);

INCLUDE_ASM("18B4", func_80033CB8);

INCLUDE_ASM("18B4", func_80033DAC);

INCLUDE_ASM("18B4", func_80033DE4);

INCLUDE_ASM("18B4", func_80033E34);

INCLUDE_ASM("18B4", func_80033E74);

INCLUDE_ASM("18B4", func_80033EDC);

INCLUDE_ASM("18B4", func_80033F40);

INCLUDE_ASM("18B4", func_80033FC4);

INCLUDE_ASM("18B4", func_80034048);

INCLUDE_ASM("18B4", func_8003408C);

INCLUDE_ASM("18B4", func_80034104);

INCLUDE_ASM("18B4", func_80034150);

INCLUDE_ASM("18B4", func_80034350);

INCLUDE_ASM("18B4", func_800343F0);

INCLUDE_ASM("18B4", func_80034410);

void func_80034420(void) {
}

void func_80034428(void) {
}

INCLUDE_ASM("18B4", func_80034430);

INCLUDE_ASM("18B4", func_80034444);

INCLUDE_ASM("18B4", func_8003447C);

INCLUDE_ASM("18B4", func_800344C0);

INCLUDE_ASM("18B4", func_800345BC);

INCLUDE_ASM("18B4", func_80034600);

INCLUDE_ASM("18B4", func_800346F8);

INCLUDE_ASM("18B4", func_80034754);

INCLUDE_ASM("18B4", func_800347B4);

INCLUDE_ASM("18B4", func_800347F8);

INCLUDE_ASM("18B4", func_800348F4);

INCLUDE_ASM("18B4", func_80034974);

INCLUDE_ASM("18B4", func_80034A58);

INCLUDE_ASM("18B4", func_80034A90);

INCLUDE_ASM("18B4", func_80034B44);

INCLUDE_ASM("18B4", func_80034BB0);

INCLUDE_ASM("18B4", func_80034CAC);

INCLUDE_ASM("18B4", func_80034D18);

INCLUDE_ASM("18B4", func_80034D2C);

INCLUDE_ASM("18B4", func_80034D5C);

INCLUDE_ASM("18B4", func_80034DB0);

INCLUDE_ASM("18B4", func_80034E00);

INCLUDE_ASM("18B4", func_80034F3C);

INCLUDE_ASM("18B4", func_80034F5C);

INCLUDE_ASM("18B4", func_80034FC8);

INCLUDE_ASM("18B4", func_80035430);

INCLUDE_ASM("18B4", func_800354CC);

INCLUDE_ASM("18B4", func_80035658);

INCLUDE_ASM("18B4", func_80035744);

INCLUDE_ASM("18B4", func_80035CF0);

INCLUDE_ASM("18B4", func_80035D64);

INCLUDE_ASM("18B4", func_80035DC8);

INCLUDE_ASM("18B4", func_80035F14);

INCLUDE_ASM("18B4", func_80036038);

INCLUDE_ASM("18B4", func_80036100);

INCLUDE_ASM("18B4", func_80036190);

INCLUDE_ASM("18B4", func_80036244);

INCLUDE_ASM("18B4", func_80036298);

INCLUDE_ASM("18B4", func_800362B8);

INCLUDE_ASM("18B4", func_800363B0);

INCLUDE_ASM("18B4", func_8003642C);

INCLUDE_ASM("18B4", func_800366C0);

INCLUDE_ASM("18B4", func_8003688C);

INCLUDE_ASM("18B4", func_8003695C);

INCLUDE_ASM("18B4", func_80036A18);

INCLUDE_ASM("18B4", func_80036CA8);

INCLUDE_ASM("18B4", func_80036D30);

INCLUDE_ASM("18B4", func_80036D98);

INCLUDE_ASM("18B4", func_80036DE0);

INCLUDE_ASM("18B4", func_80036E84);

INCLUDE_ASM("18B4", func_80036EC0);

INCLUDE_ASM("18B4", func_80036F20);

INCLUDE_ASM("18B4", func_80036F4C);

INCLUDE_ASM("18B4", func_80036F78);

INCLUDE_ASM("18B4", func_80036FD8);

INCLUDE_ASM("18B4", func_80036FFC);

INCLUDE_ASM("18B4", func_80037050);

INCLUDE_ASM("18B4", func_800373AC);

INCLUDE_ASM("18B4", func_80037664);

INCLUDE_ASM("18B4", func_80037964);

INCLUDE_ASM("18B4", func_80037988);

INCLUDE_ASM("18B4", func_80037B90);

INCLUDE_ASM("18B4", func_80037BE0);

INCLUDE_ASM("18B4", func_80037C40);

INCLUDE_ASM("18B4", func_80037D10);

INCLUDE_ASM("18B4", func_80037D90);

INCLUDE_ASM("18B4", func_80037E1C);

INCLUDE_ASM("18B4", func_8003832C);

INCLUDE_ASM("18B4", func_800387FC);

INCLUDE_ASM("18B4", func_8003884C);

INCLUDE_ASM("18B4", func_800388C4);

INCLUDE_ASM("18B4", func_800388E8);

INCLUDE_ASM("18B4", func_80038A84);

INCLUDE_ASM("18B4", func_80038BC4);

INCLUDE_ASM("18B4", func_80038C04);

INCLUDE_ASM("18B4", func_80038C48);

INCLUDE_ASM("18B4", func_80038C6C);

INCLUDE_ASM("18B4", func_80038E70);

INCLUDE_ASM("18B4", func_80038F04);

INCLUDE_ASM("18B4", func_80038F64);

INCLUDE_ASM("18B4", func_80038FB8);

INCLUDE_ASM("18B4", func_80038FEC);

INCLUDE_ASM("18B4", func_80039010);

INCLUDE_ASM("18B4", func_80039034);

INCLUDE_ASM("18B4", func_800393C8);

INCLUDE_ASM("18B4", func_80039450);

INCLUDE_ASM("18B4", func_800395C8);

INCLUDE_ASM("18B4", func_80039644);

INCLUDE_ASM("18B4", func_800396C0);

INCLUDE_ASM("18B4", func_8003973C);

INCLUDE_ASM("18B4", func_800397C8);

INCLUDE_ASM("18B4", func_80039850);

INCLUDE_ASM("18B4", func_800398EC);

INCLUDE_ASM("18B4", func_800399D0);

INCLUDE_ASM("18B4", func_80039A74);

INCLUDE_ASM("18B4", func_80039AB0);

INCLUDE_ASM("18B4", func_80039B40);

INCLUDE_ASM("18B4", func_80039BE0);

INCLUDE_ASM("18B4", func_80039CEC);

INCLUDE_ASM("18B4", func_80039E40);

INCLUDE_ASM("18B4", func_80039EDC);

INCLUDE_ASM("18B4", func_80039F5C);

INCLUDE_ASM("18B4", func_80039FEC);

INCLUDE_ASM("18B4", func_8003A078);

INCLUDE_ASM("18B4", func_8003A0E8);

INCLUDE_ASM("18B4", func_8003A1A4);

INCLUDE_ASM("18B4", func_8003A28C);

INCLUDE_ASM("18B4", func_8003A30C);

INCLUDE_ASM("18B4", func_8003A35C);

INCLUDE_ASM("18B4", func_8003A3AC);

INCLUDE_ASM("18B4", func_8003A434);

INCLUDE_ASM("18B4", func_8003A4BC);

INCLUDE_ASM("18B4", func_8003A51C);

INCLUDE_ASM("18B4", func_8003A59C);

INCLUDE_ASM("18B4", func_8003A63C);

INCLUDE_ASM("18B4", func_8003A79C);

INCLUDE_ASM("18B4", func_8003A8A8);

INCLUDE_ASM("18B4", func_8003A98C);

INCLUDE_ASM("18B4", func_8003AA74);

INCLUDE_ASM("18B4", func_8003AB84);

INCLUDE_ASM("18B4", func_8003ACE4);

INCLUDE_ASM("18B4", func_8003AD14);

INCLUDE_ASM("18B4", func_8003AE38);

INCLUDE_ASM("18B4", func_8003AED8);

INCLUDE_ASM("18B4", func_8003AF78);

INCLUDE_ASM("18B4", func_8003AFC0);

INCLUDE_ASM("18B4", func_8003B008);

INCLUDE_ASM("18B4", func_8003B05C);

INCLUDE_ASM("18B4", func_8003B16C);

INCLUDE_ASM("18B4", func_8003B27C);

INCLUDE_ASM("18B4", func_8003B2CC);

INCLUDE_ASM("18B4", func_8003B32C);

INCLUDE_ASM("18B4", func_8003B35C);

INCLUDE_ASM("18B4", func_8003B48C);

INCLUDE_ASM("18B4", func_8003B4BC);

INCLUDE_ASM("18B4", func_8003B4EC);

INCLUDE_ASM("18B4", func_8003B51C);

INCLUDE_ASM("18B4", func_8003B53C);

INCLUDE_ASM("18B4", func_8003B54C);

INCLUDE_ASM("18B4", func_8003B55C);

INCLUDE_ASM("18B4", func_8003B56C);

INCLUDE_ASM("18B4", func_8003B58C);

INCLUDE_ASM("18B4", func_8003B5A0);

INCLUDE_ASM("18B4", func_8003B5B4);

INCLUDE_ASM("18B4", func_8003B5C0);

INCLUDE_ASM("18B4", func_8003B5D4);

INCLUDE_ASM("18B4", func_8003B5EC);

INCLUDE_ASM("18B4", func_8003B600);

INCLUDE_ASM("18B4", func_8003B614);

INCLUDE_ASM("18B4", func_8003B628);

INCLUDE_ASM("18B4", func_8003B634);

INCLUDE_ASM("18B4", func_8003B640);

INCLUDE_ASM("18B4", func_8003B64C);

INCLUDE_ASM("18B4", func_8003B66C);

INCLUDE_ASM("18B4", func_8003B67C);

INCLUDE_ASM("18B4", func_8003B69C);

INCLUDE_ASM("18B4", func_8003B6BC);

INCLUDE_ASM("18B4", func_8003B6DC);

INCLUDE_ASM("18B4", func_8003B6EC);

INCLUDE_ASM("18B4", func_8003B710);

INCLUDE_ASM("18B4", func_8003B72C);

INCLUDE_ASM("18B4", func_8003B748);

INCLUDE_ASM("18B4", func_8003B784);

INCLUDE_ASM("18B4", func_8003B7A8);

INCLUDE_ASM("18B4", func_8003B7F0);

INCLUDE_ASM("18B4", func_8003B810);

INCLUDE_ASM("18B4", func_8003B854);

INCLUDE_ASM("18B4", func_8003B87C);

INCLUDE_ASM("18B4", func_8003B8A0);

INCLUDE_ASM("18B4", func_8003B8B0);

INCLUDE_ASM("18B4", func_8003B8CC);

INCLUDE_ASM("18B4", func_8003B8F4);

INCLUDE_ASM("18B4", func_8003B91C);

INCLUDE_ASM("18B4", func_8003B958);

INCLUDE_ASM("18B4", func_8003B97C);

INCLUDE_ASM("18B4", func_8003B9A4);

INCLUDE_ASM("18B4", func_8003B9CC);

INCLUDE_ASM("18B4", func_8003B9EC);

INCLUDE_ASM("18B4", func_8003BA10);

INCLUDE_ASM("18B4", func_8003BA68);

INCLUDE_ASM("18B4", func_8003BAC0);

INCLUDE_ASM("18B4", func_8003BADC);

INCLUDE_ASM("18B4", func_8003BB0C);

INCLUDE_ASM("18B4", func_8003BB44);

INCLUDE_ASM("18B4", func_8003BB7C);

INCLUDE_ASM("18B4", func_8003BBAC);

INCLUDE_ASM("18B4", func_8003BBDC);

INCLUDE_ASM("18B4", func_8003BC0C);

INCLUDE_ASM("18B4", func_8003BC6C);

INCLUDE_ASM("18B4", func_8003BC9C);

INCLUDE_ASM("18B4", func_8003BD1C);

INCLUDE_ASM("18B4", func_8003BD7C);

INCLUDE_ASM("18B4", func_8003BDFC);

INCLUDE_ASM("18B4", func_8003BE8C);

INCLUDE_ASM("18B4", func_8003BF3C);

INCLUDE_ASM("18B4", func_8003BF8C);

INCLUDE_ASM("18B4", func_8003C21C);

INCLUDE_ASM("18B4", func_8003C4AC);

INCLUDE_ASM("18B4", func_8003C73C);

INCLUDE_ASM("18B4", func_8003C8DC);

INCLUDE_ASM("18B4", func_8003CA7C);

INCLUDE_ASM("18B4", func_8003CC1C);

INCLUDE_ASM("18B4", func_8003CD9C);

INCLUDE_ASM("18B4", func_8003CE0C);

INCLUDE_ASM("18B4", func_8003CE8C);

INCLUDE_ASM("18B4", func_8003CEBC);

INCLUDE_ASM("18B4", func_8003CEDC);

INCLUDE_ASM("18B4", func_8003D024);

INCLUDE_ASM("18B4", func_8003D0C0);

INCLUDE_ASM("18B4", func_8003D0F0);

INCLUDE_ASM("18B4", func_8003D120);

INCLUDE_ASM("18B4", func_8003D150);

INCLUDE_ASM("18B4", func_8003D184);

INCLUDE_ASM("18B4", func_8003D1B4);

INCLUDE_ASM("18B4", func_8003D1E4);

u16 func_8003D214(void) {
    return D_800504AE;
}

INCLUDE_ASM("18B4", func_8003D224);

INCLUDE_ASM("18B4", func_8003D23C);

INCLUDE_ASM("18B4", func_8003D258);

INCLUDE_ASM("18B4", func_8003D334);

INCLUDE_ASM("18B4", func_8003D51C);

INCLUDE_ASM("18B4", func_8003D670);

INCLUDE_ASM("18B4", func_8003D71C);

INCLUDE_ASM("18B4", func_8003D7A4);

INCLUDE_ASM("18B4", func_8003D7D0);

INCLUDE_ASM("18B4", func_8003D828);

INCLUDE_ASM("18B4", func_8003D8A0);

INCLUDE_ASM("18B4", func_8003D8CC);

INCLUDE_ASM("18B4", func_8003D8F8);

INCLUDE_ASM("18B4", func_8003D948);

INCLUDE_ASM("18B4", func_8003DACC);

INCLUDE_ASM("18B4", func_8003DB74);

INCLUDE_ASM("18B4", func_8003DBA0);

INCLUDE_ASM("18B4", func_8003DBD0);

INCLUDE_ASM("18B4", func_8003DC60);

INCLUDE_ASM("18B4", func_8003DC88);

INCLUDE_ASM("18B4", func_8003DCB0);

INCLUDE_ASM("18B4", func_8003DCD8);

INCLUDE_ASM("18B4", func_8003DCE8);

INCLUDE_ASM("18B4", func_8003DCF8);

INCLUDE_ASM("18B4", func_8003DD08);

INCLUDE_ASM("18B4", func_8003DD18);

INCLUDE_ASM("18B4", func_8003DD84);

INCLUDE_ASM("18B4", func_8003DDA4);

INCLUDE_ASM("18B4", func_8003DDBC);

INCLUDE_ASM("18B4", func_8003DDF4);

INCLUDE_ASM("18B4", func_8003DE2C);

INCLUDE_ASM("18B4", func_8003DE4C);

INCLUDE_ASM("18B4", func_8003DE6C);

INCLUDE_ASM("18B4", func_8003DE84);

INCLUDE_ASM("18B4", func_8003DE9C);

INCLUDE_ASM("18B4", func_8003DFD4);

INCLUDE_ASM("18B4", func_8003E100);

INCLUDE_ASM("18B4", func_8003E244);

INCLUDE_ASM("18B4", func_8003E268);

INCLUDE_ASM("18B4", func_8003E28C);

INCLUDE_ASM("18B4", func_8003E2B0);

INCLUDE_ASM("18B4", func_8003E2D0);

INCLUDE_ASM("18B4", func_8003E3D4);

INCLUDE_ASM("18B4", func_8003E454);

INCLUDE_ASM("18B4", func_8003E9DC);

INCLUDE_ASM("18B4", func_8003EC60);

INCLUDE_ASM("18B4", func_8003EF30);

INCLUDE_ASM("18B4", func_8003F398);

INCLUDE_ASM("18B4", func_8003F420);

INCLUDE_ASM("18B4", func_8003F500);

INCLUDE_ASM("18B4", func_8003F5F4);

INCLUDE_ASM("18B4", func_8003F644);

INCLUDE_ASM("18B4", func_8003F830);

INCLUDE_ASM("18B4", func_8003F99C);

INCLUDE_ASM("18B4", func_8003FA9C);

INCLUDE_ASM("18B4", func_8003FAAC);

INCLUDE_ASM("18B4", func_8003FB8C);

INCLUDE_ASM("18B4", func_8003FE74);

INCLUDE_ASM("18B4", func_8003FE98);

INCLUDE_ASM("18B4", func_8004018C);

INCLUDE_ASM("18B4", func_80040238);

INCLUDE_ASM("18B4", func_800404F4);

INCLUDE_ASM("18B4", func_80040560);

INCLUDE_ASM("18B4", func_80040594);

INCLUDE_ASM("18B4", func_80040628);

INCLUDE_ASM("18B4", func_80040648);

INCLUDE_ASM("18B4", func_8004076C);

INCLUDE_ASM("18B4", func_80040898);

INCLUDE_ASM("18B4", func_800408F8);

INCLUDE_ASM("18B4", func_80040950);

INCLUDE_ASM("18B4", func_800409E0);

INCLUDE_ASM("18B4", func_80040A40);

INCLUDE_ASM("18B4", func_80040AC8);

INCLUDE_ASM("18B4", func_80040B84);

INCLUDE_ASM("18B4", func_80040BC4);

INCLUDE_ASM("18B4", func_80040C88);

INCLUDE_ASM("18B4", func_80040CA8);

INCLUDE_ASM("18B4", func_80041620);

INCLUDE_ASM("18B4", func_80041654);

INCLUDE_ASM("18B4", func_80041810);

INCLUDE_ASM("18B4", func_800418D8);

INCLUDE_ASM("18B4", func_80041AFC);

INCLUDE_ASM("18B4", func_80041CD4);

INCLUDE_ASM("18B4", func_80041D28);

INCLUDE_ASM("18B4", func_80041E30);

INCLUDE_ASM("18B4", func_80041EFC);

INCLUDE_ASM("18B4", func_80041F14);

INCLUDE_ASM("18B4", func_80041F4C);

INCLUDE_ASM("18B4", func_80041FD8);

u16 func_80042038(u16* arg0) {
    return *arg0;
}

INCLUDE_ASM("18B4", func_80042044);

INCLUDE_ASM("18B4", func_800420C0);

INCLUDE_ASM("18B4", func_800420E0);

INCLUDE_ASM("18B4", func_80042100);

INCLUDE_ASM("18B4", func_80042120);

INCLUDE_ASM("18B4", func_80042144);

INCLUDE_ASM("18B4", func_80042168);

INCLUDE_ASM("18B4", func_80042270);

INCLUDE_ASM("18B4", func_80042304);

INCLUDE_ASM("18B4", func_80042394);

INCLUDE_ASM("18B4", func_8004242C);

INCLUDE_ASM("18B4", func_800424C4);

INCLUDE_ASM("18B4", func_800425F8);

INCLUDE_ASM("18B4", func_8004262C);
