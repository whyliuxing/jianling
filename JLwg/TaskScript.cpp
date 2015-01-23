#include "stdafx.h"
#include "TaskScript.h"
#include "JLwg.h"
#include <string>
#include <tchar.h>



FunTask ft[400] =
{
	{ TEXT("221"), &TaskScript::Task_221 },//新手任务1
	{ TEXT("222"), &TaskScript::Task_222 },//新手任务2
	{ TEXT("223"), &TaskScript::Task_223 },//新手任务3
	{ TEXT("224"), &TaskScript::Task_224 },//新手任务4
	{ TEXT("231"), &TaskScript::Task_231 },//新手任务5
	{ TEXT("232"), &TaskScript::Task_232 },//新手任务6
	{ TEXT("227"), &TaskScript::Task_227 },//新手任务7
	{ TEXT("243"), &TaskScript::Task_243 },//新手任务8
	{ TEXT("301"), &TaskScript::Task_301 },//1-1
	{ TEXT("302"), &TaskScript::Task_302 },//1-2
	{ TEXT("303"), &TaskScript::Task_303 },//1-3
	{ TEXT("497"), &TaskScript::Task_497 },//1-4
	{ TEXT("304"), &TaskScript::Task_304 },//1-5
	{ TEXT("305"), &TaskScript::Task_305 },//1-6
	{ TEXT("306"), &TaskScript::Task_306 },//1-7
	{ TEXT("307"), &TaskScript::Task_307 },//1-8
	{ TEXT("308"), &TaskScript::Task_308 },//1-9
	{ TEXT("309"), &TaskScript::Task_309 },//1-10
	{ TEXT("310"), &TaskScript::Task_310 },//1-11
	//{ TEXT("311"), &TaskScript::Task_311 },//1-12
};



TaskScript::TaskScript(void)
{
}

TaskScript::~TaskScript(void)
{

}


//功能函数区
/*
70=f
27=esc
87=w
32=space
*/



/************************************************************************/
/*新手村任务开始 */
/************************************************************************/
/*写日志*/
void TaskScript::log(TCHAR szFormat[], ...)
{
	TCHAR buffer[BUFSIZ] = { 0 };

	va_list argptr;
	va_start(argptr, szFormat);
	wvsprintf(buffer, szFormat, argptr);
	va_end(argptr);
	OutputDebugString(buffer);
}

void TaskScript::BeginTask()
{
	TaskScript ts;
	try
	{
		while (1)
		{
		DWORD pStartAddr = gcall.GetTaskStartAddr();//获取任务开始地址
		DWORD ID = gcall.GetTaskID(0, pStartAddr);//获得当前任务ID
		DWORD info = gcall.GetPresentTaskIndexes(0, pStartAddr);//获得当前做到第几个小任务
		DWORD nameid = gcall.GetTaskNameID(0, pStartAddr);//获取当前任务名id
		wchar_t* taskname = gcall.GatTaskName(nameid);//获得当前任务名

		if (ID == -1 || info == -1)
		{
			log(TEXT("获取任务失败..address:%x,id:%d,info:%d"), pStartAddr, ID, info);
			Sleep(2000);
		}
	
		TCHAR szBu_id[20] = { 0 };
		wsprintf(szBu_id, TEXT("%d"), ID);
		TCHAR szbu[20] = { 0 };
		for (int i = 0; i < 400; i++)
		{
			if (lstrcmp(ft[i].taskname, szBu_id) == 0)
			{
				wsprintf(szbu, TEXT("任务函数开始执行.id:%s,task_id:%d,数组下标:%d"), ft[i].taskname, info, i);
				log(szbu);
				(ts.*ft[i].fp)(info);
				log(TEXT("任务函数执行完成"));
				break;
			}
			else if (lstrcmp(ft[i].taskname, TEXT("")) == 0)
			{
				break;
			}
		}
		}


		//Task_221_2();
	}
	catch (...)
	{
		log(TEXT("获取任务异常"));
	}
}

void TaskScript::Task_221(int taskid)
{
	switch (taskid)
	{
	case 1:
		//gcall.SetMouseMode();
		Sleep(1000);
		gcall.KeyPress(27);
		Sleep(500);
		gcall.KeyPress(27);
		Sleep(500);
		gcall.DeliverQuests(221, taskid, L"진영");
		Sleep(500);
		break;
	case 2:
		log(TEXT("开始走路"));
		gcall.Stepto(36942, -12657, 2336);
		Sleep(500);
		log(TEXT("捡物"));
		gcall.PickupTask();
		/*Sleep(3000);
		log(TEXT("按F"));
		gcall.KeyPress(70);*/
		Sleep(1000);
		break;
	case 3:
		gcall.WearEquipment(L"홍문파 도복", 2);//穿装备
		Sleep(1000);
		break;
	case 4:
		gcall.DeliverQuests(221, taskid, L"진영");
		Sleep(5000);
		break;
	case 5:
		gcall.Stepto(37084, -12695, 2336);
		gcall.Stepto(37200, -12506, 2336);
		gcall.Stepto(37274, -12252, 2336);
		gcall.Stepto(37012, -12103, 2336);
		Sleep(2000);
		break;
	case 6:
		gcall.Stepto(36859, -12302, 2336);
		gcall.Stepto(36745, -12502, 2336);
		gcall.Stepto(36712, -12601, 2336);
		Sleep(1000);
		gcall.PickupTask(180);
		Sleep(1000);
		break;
	case 7:
		gcall.DeliverQuests(221, taskid, L"길홍");
		Sleep(1000);
		break;
	}
}

void TaskScript::Task_222(int taskid)
{
	switch (taskid)
	{
	case 1:
		gcall.Stepto(36725, -12478, 2334);
		gcall.Stepto(36810, -12389, 2334);
		gcall.Stepto(36874, -12289, 2334);
		gcall.Stepto(36949, -12218, 2334);
		Sleep(1000);
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		gcall.DeliverQuests(222, taskid, L"진영");
		Sleep(1000);
		break;
	}

}


void TaskScript::Task_223(int taskid)
{
	switch (taskid)
	{
	case 1:
		//log(_T("执行2231"));
		gcall.Stepto(36981, -12151, 2334);
		gcall.Stepto(37066, -12060, 2333);
		gcall.Stepto(37158, -11956, 2333);
		gcall.Stepto(37262, -11847, 2331);
		gcall.Stepto(37374, -11725, 2316);
		gcall.Stepto(37552, -11527, 2216);
		gcall.Stepto(37786, -11331, 2171);
		gcall.Stepto(37980, -11222, 2172);
		gcall.Stepto(38158, -11134, 2178);
		gcall.Stepto(38380, -11019, 2163);
		gcall.Stepto(38600, -10887, 2148);
		gcall.Stepto(38852, -10762, 2139);
		gcall.Stepto(39091, -10683, 2142);
		gcall.Stepto(39273, -10627, 2151);
		gcall.Stepto(39462, -10564, 2152);
		Sleep(500);
		break;
	case 2:
		gcall.Stepto(39475, -10586, 2156);
		Sleep(500);
		gcall.DeliverQuests(223, taskid, L"영묵");
		Sleep(1000);
		break;
	case 3:
		gcall.NewSpend(2.5);
		gcall.Stepto(38949, -10508, 2153);
		gcall.Stepto(38313, -10305, 2204);
		gcall.Stepto(37900, -10167, 2241);
		gcall.Stepto(37281, -9861, 2222);
		gcall.Stepto(36726, -9581, 2195);
		gcall.Stepto(35960, -9459, 2268);
		gcall.Stepto(35217, -9310, 2183);
		gcall.Stepto(34561, -8948, 2209);
		gcall.Stepto(33961, -8841, 2257);
		gcall.Stepto(33285, -9068, 2535);
		gcall.Stepto(32961, -8874, 2596);
		gcall.Stepto(32993, -8704, 2601);
		gcall.Stepto(33045, -8681, 2602);
		gcall.NewSpend(1);
		Sleep(1000);
		gcall.KeyPress(27);
		Sleep(500);
		gcall.Stepto(33712, -8121, 2636);
		Sleep(1000);
		gcall.KeyPress(27);
		Sleep(500);
		gcall.KeyPress(27);
		Sleep(500);
		gcall.Stepto(33712, -8121, 2636);
		Sleep(1000);
		break;
	case 4:
		gcall.Stepto(33823, -8043, 2636);
		Sleep(1000);
		gcall.DeliverQuests(223, taskid, L"무성");
		break;

	}


}


void TaskScript::Task_224(int taskid)
{
	switch (taskid)
	{
	case 1:
		gcall.NewSpend(2.5);
		gcall.Stepto(33976, -8212, 2652);
		gcall.Stepto(34123, -8347, 2620);
		gcall.Stepto(34316, -8508, 2225);
		gcall.Stepto(34511, -8662, 2216);
		gcall.Stepto(34668, -8779, 2214);
		gcall.Stepto(34790, -8870, 2211);
		gcall.Stepto(34913, -9068, 2206);
		gcall.Stepto(35091, -9228, 2201);
		gcall.Stepto(35294, -9340, 2184);
		gcall.Stepto(35451, -9387, 2186);
		gcall.Stepto(35698, -9408, 2241);
		gcall.Stepto(35942, -9448, 2268);
		gcall.Stepto(36187, -9488, 2267);
		gcall.Stepto(36434, -9529, 2235);
		gcall.Stepto(36678, -9570, 2194);
		gcall.Stepto(36692, -9572, 2193);
		gcall.Stepto(36778, -9669, 2202);
		gcall.Stepto(36921, -9863, 2217);
		gcall.Stepto(37155, -9942, 2211);
		gcall.Stepto(37391, -10021, 2220);
		gcall.Stepto(37623, -10098, 2234);
		gcall.Stepto(37697, -10042, 2243);
		gcall.Stepto(37878, -9864, 2266);
		gcall.Stepto(38059, -9696, 2288);
		gcall.Stepto(38242, -9521, 2301);
		gcall.Stepto(38421, -9349, 2324);
		gcall.Stepto(38600, -9183, 2353);
		gcall.Stepto(38787, -9020, 2360);
		gcall.Stepto(38882, -8924, 2360);
		gcall.Stepto(38897, -8908, 2360);
		gcall.Stepto(38922, -8879, 2360);
		gcall.NewSpend(1);
		Sleep(1000);
		break;
	case 2:
		gcall.DeliverQuests(224, taskid, L"홍석근", 0);
		Sleep(1000);
		break;
	case 3:
		gcall.Stepto(38945, -8763, 2360);
		gcall.Stepto(38618, -8439, 2508);
		gcall.Stepto(38244, -8048, 2705);
		gcall.Stepto(38047, -7771, 2739);
		gcall.Stepto(37904, -7456, 2739);
		gcall.Stepto(37771, -7355, 2743);
		gcall.Stepto(37619, -7377, 2743);
		Sleep(1000);
		break;
	case 4:
		Sleep(1000);
		gcall.Stepto(37619, -7377, 2743);
		Sleep(1000);
		gcall.PickupTask();
		//Sleep(4000);
		//gcall.KeyPress(70);
		Sleep(2000);
		break;
	case 5:
		gcall.DeliverQuests(224, 5, NULL,1,0,1);
		Sleep(3000);
		break;
	case 6:
		gcall.Stepto(37685, -7270, 2743);
		Sleep(500);
		gcall.DeliverQuests(224, taskid, L"홍석근");
		Sleep(1000);
		break;
	}
}


void TaskScript::Task_231(int taskid)
{
	switch (taskid)
	{
	case 1:
		gcall.NewSpend(2.5);
		gcall.Stepto(37796, -7362, 2743);
		gcall.Stepto(37908, -7463, 2739);
		gcall.Stepto(38061, -7857, 2739);
		gcall.Stepto(38165, -7999, 2732);
		gcall.Stepto(38297, -8122, 2672);
		gcall.Stepto(38402, -8237, 2616);
		gcall.Stepto(38575, -8415, 2525);
		gcall.Stepto(38747, -8593, 2435);
		gcall.Stepto(38918, -8770, 2360);
		gcall.Stepto(39010, -8862, 2360);
		gcall.Stepto(39133, -8906, 2360);
		gcall.Stepto(39290, -8961, 2357);
		gcall.Stepto(39527, -9032, 2277);
		gcall.Stepto(39766, -9099, 2189);
		gcall.Stepto(39874, -9140, 2157);
		gcall.Stepto(39935, -9252, 2148);
		gcall.Stepto(40026, -9422, 2145);
		gcall.Stepto(40158, -9439, 2145);
		gcall.Stepto(40402, -9480, 2072);
		gcall.Stepto(40562, -9511, 2045);
		gcall.Stepto(40773, -9582, 2016);
		gcall.Stepto(40836, -9562, 2012);
		gcall.Stepto(41019, -9506, 1992);
		gcall.Stepto(41185, -9441, 2039);
		gcall.Stepto(41418, -9367, 2127);
		gcall.Stepto(41621, -9306, 2202);
		gcall.Stepto(41901, -9220, 2226);
		gcall.Stepto(42135, -9147, 2226);
		gcall.Stepto(42373, -9073, 2232);
		gcall.Stepto(42489, -9037, 2232);
		gcall.Stepto(42523, -9026, 2232);
		gcall.NewSpend(1);
		Sleep(1000);
		gcall.DeliverQuests(231, 1, L"영묵");
		Sleep(1000);
		break;
	case 2:
		gcall.WearEquipment(L"수련용 도끼", 1);
		Sleep(1000);
		break;
	case 3:
		gcall.Stepto(42894, -8913, 2226);
		gcall.Stepto(43123, -8821, 2226);
		gcall.Stepto(43508, -8667, 2226);
		gcall.Stepto(43894, -8569, 2226);
		gcall.Stepto(44196, -8470, 2226);
		Sleep(5000);
		break;
	}
}


void TaskScript::Task_232(int taskid)
{
	switch (taskid)
	{
	case 1:
		gcall.DeliverQuests(232, 1, L"영묵");
		Sleep(1000);
		break;
	case 2:
		gcall.DeliverQuests(232, 2, NULL);
		Sleep(500);
		gcall.DeliverQuests(232, 2, NULL);
		Sleep(500);
		gcall.DeliverQuests(232, 2, NULL);
		Sleep(1000);
		break;
	case 3:
		gcall.DeliverQuests(232, 4, NULL);
		Sleep(500);
		gcall.DeliverQuests(232, 4, NULL);
		Sleep(500);
		gcall.DeliverQuests(232, 4, NULL);
		Sleep(1000);
		break;
	}
}

void TaskScript::Task_227(int taskid)
{
	switch (taskid)
	{
	case 1:
		gcall.DeliverQuests(227, 1, L"영묵");
		Sleep(1000);
		gcall.DeliverQuests(227, 1, NULL);
		Sleep(1000);
		break;
	case 2:
		//log(_T("227-2"));
		gcall.DeliverQuests(227, 2, L"영묵", 1,0,0);
		Sleep(1000);
		break;
	case 3:
		gcall.NewSpend(2.5);
		gcall.Stepto(44185, -8432, 2226);
		gcall.Stepto(44135, -8450, 2226);
		gcall.Stepto(43900, -8532, 2226);
		gcall.Stepto(43666, -8614, 2226);
		gcall.Stepto(43433, -8695, 2226);
		gcall.Stepto(43199, -8778, 2226);
		gcall.Stepto(42965, -8860, 2226);
		gcall.Stepto(42731, -8942, 2232);
		gcall.Stepto(42497, -9024, 2232);
		gcall.Stepto(42263, -9105, 2226);
		gcall.Stepto(42027, -9180, 2226);
		gcall.Stepto(41910, -9215, 2226);
		gcall.Stepto(41855, -9232, 2226);
		gcall.Stepto(41616, -9303, 2201);
		gcall.Stepto(41376, -9377, 2111);
		gcall.Stepto(41139, -9450, 2023);
		gcall.Stepto(40902, -9524, 2008);
		gcall.Stepto(40665, -9597, 2028);
		gcall.Stepto(40631, -9608, 2032);
		gcall.Stepto(40626, -9835, 2052);
		gcall.Stepto(40615, -10082, 2067);
		gcall.Stepto(40604, -10330, 2062);
		gcall.Stepto(40594, -10578, 2059);
		gcall.Stepto(40583, -10826, 2051);
		gcall.Stepto(40580, -11074, 2030);
		gcall.Stepto(40688, -11295, 1999);
		gcall.Stepto(40795, -11452, 1990);
		gcall.Stepto(40926, -11662, 1957);
		gcall.Stepto(41058, -11873, 1888);
		gcall.Stepto(41189, -12083, 1831);
		gcall.Stepto(41321, -12294, 1770);
		gcall.Stepto(41448, -12494, 1722);
		gcall.Stepto(41549, -12581, 1709);
		gcall.Stepto(41732, -12748, 1693);
		gcall.Stepto(41918, -12911, 1692);
		gcall.Stepto(42108, -13078, 1630);
		gcall.Stepto(42293, -13242, 1504);
		gcall.Stepto(42473, -13414, 1446);
		gcall.Stepto(42658, -13583, 1326);
		gcall.Stepto(42847, -13743, 1246);
		gcall.Stepto(43043, -13901, 1208);
		gcall.Stepto(43236, -14057, 1211);
		gcall.Stepto(43429, -14212, 1222);
		gcall.Stepto(43451, -14230, 1223);
		gcall.Stepto(43450, -14410, 1230);
		gcall.Stepto(43456, -14658, 1239);
		gcall.Stepto(43462, -14906, 1249);
		gcall.Stepto(43468, -15158, 1256);
		gcall.Stepto(43468, -15403, 1269);
		gcall.Stepto(43491, -15551, 1270);
		gcall.Stepto(43542, -15796, 1270);
		gcall.Stepto(43594, -16038, 1271);
		gcall.Stepto(43646, -16285, 1270);
		gcall.Stepto(43697, -16528, 1279);
		gcall.Stepto(43749, -16771, 1281);
		gcall.Stepto(43800, -17014, 1283);
		gcall.Stepto(43852, -17259, 1284);
		gcall.Stepto(43877, -17379, 1284);
		gcall.NewSpend(1);
		Sleep(2000);
		break;
	case 4:
		gcall.Stepto(43964, -17699, 1291);
		gcall.Stepto(44041, -17994, 1313);
		gcall.Stepto(44417, -18314, 1316);
		gcall.Stepto(44741, -18653, 1277);
		gcall.Stepto(44822, -19080, 1214);
		gcall.Stepto(44752, -19269, 1185);
		gcall.Stepto(44500, -19680, 1106);
		gcall.Stepto(44091, -20182, 993);
		gcall.Stepto(44127, -20791, 1018);
		gcall.Stepto(44149, -21160, 1018);
		Sleep(500);
		gcall.FindThenKill(0, 600, modeNormal | modeAoe | modeGoback);
		Sleep(1000);
		break;
	case 5:
		Sleep(1000);
		gcall.Stepto(44149, -21306, 1018);
		Sleep(10000);
		break;
	case 6:
		Sleep(1000);
		gcall.KeyPress(49);
		//gcall.DeliverQuests(227, taskid, 0, 0, 0, 1);
		Sleep(25000);
		break;
	case 7:
		//gcall.UseItem(L"작은 야채 만두");
		gcall.ChiYao(L"약수 회복약");
		Sleep(2000);
		break;
	case 8:
		gcall.Stepto(44193, -21271, 1018);
		gcall.Stepto(44143, -21255, 1018);
		Sleep(1000);
		gcall.DeliverQuests(227, taskid, L"무성");
		Sleep(2000);
		break;
	case 9:
		gcall.Stepto(43833, -21202, 1018);
		Sleep(1000);
		gcall.KeyPress(70);
		Sleep(15000);
		break;
	case 10:
		Sleep(1000);
		gcall.Stepto(44133, -21241, 1018);
		Sleep(1000);
		gcall.DeliverQuests(227, 0xa, L"무성",1);
		Sleep(2000);
		break;
	}
}
void TaskScript::Task_243(int taskid)
{
	switch (taskid)
	{
	case 1:
		Sleep(1000);
		gcall.NewSpend(2.5);
		gcall.Stepto(44133, -21241, 1018);
		gcall.Stepto(44124, -21109, 1018);
		gcall.Stepto(44117, -20863, 1018);
		gcall.Stepto(44112, -20615, 1016);
		gcall.Stepto(44145, -20370, 1002);
		gcall.Stepto(44206, -20129, 1000);
		gcall.Stepto(44327, -19914, 1048);
		gcall.Stepto(44468, -19709, 1098);
		gcall.Stepto(44607, -19504, 1145);
		gcall.Stepto(44669, -19398, 1166);
		gcall.Stepto(44680, -19376, 1170);
		gcall.Stepto(44748, -19138, 1212);
		gcall.Stepto(44806, -18904, 1248);
		gcall.Stepto(44810, -18656, 1280);
		gcall.Stepto(44810, -18638, 1283);
		gcall.Stepto(44746, -18441, 1305);
		gcall.Stepto(44555, -18298, 1315);
		gcall.Stepto(44404, -18151, 1319);
		gcall.Stepto(44241, -17988, 1313);
		gcall.Stepto(44055, -17770, 1303);
		gcall.Stepto(44021, -17666, 1288);
		gcall.Stepto(43967, -17424, 1283);
		gcall.Stepto(43915, -17182, 1284);
		gcall.Stepto(43912, -17171, 1284);
		Sleep(2000);
		break;
	case 2:
		gcall.Stepto(43845, -16877, 1282);
		gcall.Stepto(43635, -16038, 1271);
		gcall.Stepto(43569, -15636, 1270);
		gcall.Stepto(43507, -15214, 1259);
		gcall.Stepto(43486, -14762, 1244);
		gcall.Stepto(43455, -14186, 1222);
		gcall.Stepto(43324, -14095, 1216);
		gcall.Stepto(43215, -14015, 1208);
		gcall.Stepto(43098, -13929, 1202);
		gcall.Stepto(42998, -13855, 1241);
		gcall.Stepto(42636, -13557, 1343);

		gcall.NewSpend(1);
		//对准角度(42848, -13754, 1246);
		Sleep(1000);
		//跑();
		Sleep(2000);
		gcall.KeyPress(27);
		Sleep(1000);
		gcall.KeyPress(27);
		break;
	case 3:
		gcall.Stepto(42992, -13866, 1240);
		gcall.Stepto(42943, -13823, 1246);
		gcall.Stepto(42752, -13658, 1264);
		gcall.Stepto(42567, -13497, 1389);
		gcall.Stepto(42376, -13332, 1446);
		gcall.Stepto(42191, -13171, 1566);
		gcall.Stepto(42006, -13011, 1683);
		gcall.Stepto(41832, -12829, 1692);
		gcall.Stepto(41686, -12633, 1699);
		gcall.Stepto(41535, -12430, 1720);
		gcall.Stepto(41396, -12229, 1769);
		gcall.Stepto(41265, -12023, 1830);
		gcall.Stepto(41126, -11811, 1888);
		gcall.Stepto(40987, -11610, 1952);
		gcall.Stepto(40846, -11400, 1991);
		gcall.Stepto(40717, -11192, 2005);
		gcall.Stepto(40584, -10977, 2036);
		gcall.Stepto(40454, -10770, 2055);
		gcall.Stepto(40307, -10575, 2110);
		gcall.Stepto(40132, -10393, 2155);
		gcall.Stepto(39961, -10217, 2158);
		gcall.Stepto(39938, -10193, 2157);
		gcall.Stepto(39520, -9973, 2156);
		Sleep(1000);
		//gcall.FindThenKill(0, 1000, modeNormal | modeAoe | modeGoback | modeTask,3,243);
		gcall.FindThenKill(0, 1000, modeNormal | modeAoe);
		Sleep(2000);
		//gcall.KeyPress(27);
		//Sleep(1000);
		//gcall.KeyPress(27);
		//Sleep(10000);
		//gcall.KeyPress(27);
		//Sleep(1000);
		//gcall.WaitPlans();
		break;

	}
}

void TaskScript::Task_301(int taskid)
{
	switch (taskid)
	{
	case 1:
		gcall.KeyPress(27);
		Sleep(1000);
		gcall.Stepto(-51145, -54519, -3042, 10, 20, 200);
		gcall.Stepto(-51066, -54428, -3033, 10, 20, 200);
		gcall.Stepto(-50982, -54346, -3012, 10, 20, 200);
		gcall.Stepto(-50894, -54264, -3012, 10, 20, 200);
		gcall.Stepto(-50829, -54178, -3012, 10, 20, 200);
		Sleep(500);
		gcall.KeyPress(27);
		Sleep(1000);
		gcall.DeliverQuests(301, taskid, L"남소유");
		Sleep(1000);
		break;
	case 2:
		Sleep(1000);
		gcall.KeyPress(27);
		Sleep(1000);
		gcall.KeyPress(27);
		Sleep(1000);
		gcall.Stepto(-50971, -54328, -3012);
		gcall.Stepto(-51195, -54484, -3035);
		gcall.Stepto(-51497, -54694, -3056);
		Sleep(1000);
		gcall.DeliverQuests(301, taskid, L"고설준");
		Sleep(3000);
		break;
	case 3:
		gcall.Stepto(-51624, -54693, -3057);
		gcall.Stepto(-51916, -54627, -3052);
		gcall.Stepto(-52231, -54719, -3041);
		gcall.Stepto(-52301, -55332, -3067);
		gcall.Stepto(-52511, -55976, -3131);
		gcall.Stepto(-52555, -56457, -3138);
		gcall.Stepto(-52434, -56425, -3136);
		Sleep(3000);
		break;
	case 4:
		gcall.Stepto(-52355, -56369, -3136);
		Sleep(1000);
		gcall.DeliverQuests(301, taskid, L"옥경원");
		Sleep(2000);
		break;
	}
}

void TaskScript::Task_302(int taskid)
{
	switch (taskid)
	{
	case 1:
		gcall.NewSpend(2.5);
		gcall.Stepto(-52156, -56474, -3142);
		gcall.Stepto(-52358, -57077, -3217);
		gcall.Stepto(-52471, -57595, -3227);
		gcall.Stepto(-52786, -57978, -3248);
		gcall.Stepto(-53102, -58250, -3231);
		gcall.Stepto(-53218, -58374, -3225);
		gcall.Stepto(-53313, -58433, -3221);
		Sleep(2000);
		break;
	case 2:
		gcall.NewSpend(1);
		gcall.FindThenKill(0, 250, modeNormal | modeAoe | modePickupOnce | modeTask,2);
		Sleep(1000);
		break;
	case 3:
		gcall.Stepto(-53112, -59050, -3240);
		gcall.Stepto(-52977, -59632, -3289);
		Sleep(1000);
		gcall.PickupTask(200);
		//Sleep(1000);
		gcall.NewSpend(2.5);
		gcall.Stepto(-52783, -58944, -3256);
		gcall.Stepto(-52641, -58438, -3262);
		gcall.Stepto(-52361, -57723, -3230);
		gcall.Stepto(-52014, -57282, -3210);
		gcall.Stepto(-51725, -57318, -3204);
		gcall.Stepto(-51118, -57476, -3193);
		gcall.Stepto(-50746, -57281, -3159);
		gcall.Stepto(-50809, -56938, -3137);
		gcall.Stepto(-50861, -56564, -3117);
		gcall.Stepto(-50826, -56371, -3114);
		gcall.NewSpend(1);
		Sleep(1000);
		//gcall.DeliverQuests(302, 3, L"곽준", 11,255,0);
		gcall.DeliverQuests(302, 3, L"곽준", 0x0000000b);
		Sleep(1000);
		gcall.NewSpend(2.5);
		gcall.Stepto(-50863, -56554, -3116);
		gcall.Stepto(-50895, -56661, -3120);
		gcall.Stepto(-50927, -56780, -3129);
		gcall.Stepto(-50920, -56904, -3138);
		gcall.Stepto(-50901, -57027, -3143);
		gcall.Stepto(-50852, -57155, -3151);
		gcall.Stepto(-50805, -57270, -3160);
		gcall.Stepto(-50763, -57387, -3165);
		gcall.Stepto(-50720, -57503, -3176);
		gcall.Stepto(-50679, -57620, -3190);
		gcall.Stepto(-50640, -57738, -3193);
		gcall.Stepto(-50611, -57858, -3197);
		gcall.Stepto(-50605, -57982, -3199);
		gcall.Stepto(-50617, -58106, -3204);
		gcall.Stepto(-50650, -58225, -3209);
		gcall.Stepto(-50716, -58330, -3222);
		gcall.Stepto(-50795, -58425, -3234);
		gcall.Stepto(-50875, -58521, -3241);
		gcall.Stepto(-50954, -58616, -3245);
		gcall.Stepto(-51018, -58721, -3248);
		gcall.Stepto(-51067, -58833, -3253);
		gcall.Stepto(-51119, -58946, -3262);
		gcall.Stepto(-51171, -59058, -3271);
		gcall.Stepto(-51223, -59171, -3277);
		gcall.Stepto(-51275, -59284, -3279);
		gcall.Stepto(-51328, -59398, -3282);
		gcall.Stepto(-51379, -59511, -3284);
		gcall.Stepto(-52165, -59457, -3270);
		gcall.Stepto(-52287, -59434, -3271);
		gcall.Stepto(-52405, -59397, -3276);
		gcall.Stepto(-52518, -59344, -3281);
		gcall.Stepto(-52630, -59292, -3285);
		gcall.Stepto(-52743, -59239, -3281);
		gcall.Stepto(-52854, -59185, -3267);
		gcall.Stepto(-52965, -59130, -3251);
		gcall.NewSpend(1);
		break;
	case 4:
		gcall.NewSpend(2.5);
		Sleep(1000);
		/*gcall.Stepto(-51338, -59411, -3283);
		gcall.Stepto(-51274, -59277, -3279);
		gcall.Stepto(-51210, -59142, -3276);
		gcall.Stepto(-51145, -59008, -3267);
		gcall.Stepto(-51081, -58874, -3256);
		gcall.Stepto(-51017, -58739, -3248);
		gcall.Stepto(-50953, -58605, -3246);
		gcall.Stepto(-50902, -58498, -3244);
		gcall.Stepto(-50848, -58386, -3235);
		gcall.Stepto(-50795, -58274, -3220);
		gcall.Stepto(-50741, -58162, -3213);
		gcall.Stepto(-50686, -58051, -3206);
		gcall.Stepto(-50632, -57939, -3199);
		gcall.Stepto(-50606, -57820, -3195);
		gcall.Stepto(-50641, -57701, -3192);
		gcall.Stepto(-50682, -57584, -3185);
		gcall.Stepto(-50723, -57467, -3174);
		gcall.Stepto(-50765, -57350, -3161);
		gcall.Stepto(-50806, -57233, -3158);
		gcall.Stepto(-50846, -57116, -3148);
		gcall.Stepto(-50866, -56994, -3141);
		gcall.Stepto(-50867, -56870, -3136);
		gcall.Stepto(-50864, -56746, -3123);
		gcall.Stepto(-50854, -56622, -3118);
		gcall.Stepto(-50839, -56499, -3115);
		gcall.Stepto(-50936, -56668, -3121);
		gcall.Stepto(-51585, -56626, -3141);
		gcall.Stepto(-52244, -56176, -3137);
		gcall.Stepto(-52231, -55402, -3065);
		gcall.Stepto(-52117, -54672, -3045);
		gcall.Stepto(-51326, -54488, -3039);
		gcall.Stepto(-50968, -54356, -3012);
		gcall.Stepto(-50751, -54242, -3012);*/
		gcall.Stepto(-52915, -58987, -3241);
		gcall.Stepto(-52878, -58882, -3243);
		gcall.Stepto(-52837, -58765, -3246);
		gcall.Stepto(-52795, -58648, -3247);
		gcall.Stepto(-52757, -58530, -3250);
		gcall.Stepto(-52719, -58412, -3252);
		gcall.Stepto(-52682, -58294, -3256);
		gcall.Stepto(-52644, -58176, -3258);
		gcall.Stepto(-52607, -58057, -3257);
		gcall.Stepto(-52569, -57939, -3255);
		gcall.Stepto(-52532, -57821, -3247);
		gcall.Stepto(-52494, -57703, -3236);
		gcall.Stepto(-52458, -57584, -3227);
		gcall.Stepto(-52426, -57464, -3225);
		gcall.Stepto(-52397, -57344, -3222);
		gcall.Stepto(-52368, -57223, -3220);
		gcall.Stepto(-52338, -57103, -3218);
		gcall.Stepto(-52309, -56982, -3216);
		gcall.Stepto(-52280, -56862, -3203);
		gcall.Stepto(-52252, -56741, -3186);
		gcall.Stepto(-52239, -56617, -3163);
		gcall.Stepto(-52234, -56494, -3146);
		gcall.Stepto(-52232, -56370, -3138);
		gcall.Stepto(-52236, -56246, -3137);
		gcall.Stepto(-52240, -56122, -3137);
		gcall.Stepto(-52244, -55998, -3137);
		gcall.Stepto(-52249, -55874, -3140);
		gcall.Stepto(-52253, -55750, -3144);
		gcall.Stepto(-52257, -55626, -3145);
		gcall.Stepto(-52260, -55502, -3100);
		gcall.Stepto(-52260, -55378, -3062);
		gcall.Stepto(-52258, -55254, -3058);
		gcall.Stepto(-52257, -55130, -3053);
		gcall.Stepto(-52256, -55006, -3048);
		gcall.Stepto(-52254, -54882, -3043);
		gcall.Stepto(-52253, -54758, -3040);
		gcall.Stepto(-52148, -54705, -3043);
		gcall.Stepto(-52029, -54669, -3047);
		gcall.Stepto(-51910, -54634, -3051);
		gcall.Stepto(-51788, -54611, -3055);
		gcall.Stepto(-51666, -54591, -3054);
		gcall.Stepto(-51544, -54567, -3047);
		gcall.Stepto(-51425, -54533, -3043);
		gcall.Stepto(-51309, -54490, -3039);
		gcall.Stepto(-51194, -54444, -3031);
		gcall.Stepto(-51078, -54400, -3030);
		gcall.Stepto(-50968, -54352, -3012);
		gcall.Stepto(-50867, -54293, -3012);
		gcall.Stepto(-50759, -54231, -3012);
		gcall.NewSpend(1);
		Sleep(15000);
		gcall.DeliverQuests(302,taskid,L"도천풍");
		Sleep(2000);
		break;
	}

}

void TaskScript::Task_303(int taskid)
{
	switch (taskid)
	{
	case 1:
		Sleep(1000);
		gcall.NewSpend(1);
		gcall.Stepto(-50948, -54337, -3012);
		gcall.Stepto(-51138, -54438, -3030);
		gcall.Stepto(-51340, -54544, -3042);
		gcall.Stepto(-51552, -54663, -3056);
		Sleep(1000);
		gcall.DeliverQuests(303,taskid, L"고설준");
		Sleep(2000);
		break;
	case 2:
		gcall.NewSpend(2.5);
		Sleep(1000);
		gcall.Stepto(-51757, -54534, -3053);
		gcall.Stepto(-52222, -54696, -3042);
		gcall.Stepto(-52280, -55311, -3062);
		gcall.Stepto(-52314, -56071, -3134);
		gcall.Stepto(-52307, -56737, -3188);
		gcall.Stepto(-53210, -57035, -3169);
		gcall.Stepto(-53666, -57057, -3151);
		gcall.Stepto(-54240, -57131, -3137);
		gcall.Stepto(-54748, -57879, -3143);
		gcall.Stepto(-54724, -58722, -3195);
		gcall.Stepto(-54690, -59305, -3286);
		gcall.Stepto(-55002, -59816, -3318);
		gcall.Stepto(-55428, -60081, -3328);
		gcall.Stepto(-56144, -59746, -3313);
		gcall.Stepto(-57055, -59236, -3318);
		gcall.Stepto(-57498, -58933, -3318);
		gcall.Stepto(-58637, -58472, -3242);
		gcall.Stepto(-59088, -58282, -3210);
		gcall.Stepto(-59639, -56281, -3315);
		gcall.Stepto(-56381, -59565, -3316);
		gcall.Stepto(-56482, -59493, -3317);
		gcall.Stepto(-56582, -59420, -3314);
		gcall.Stepto(-56679, -59343, -3310);
		gcall.Stepto(-56771, -59260, -3312);
		gcall.Stepto(-56863, -59177, -3311);
		gcall.Stepto(-56955, -59094, -3309);
		gcall.Stepto(-57048, -59011, -3308);
		gcall.Stepto(-57140, -58928, -3311);
		gcall.Stepto(-57230, -58843, -3313);
		gcall.Stepto(-57320, -58757, -3314);
		gcall.Stepto(-57404, -58667, -3314);
		gcall.Stepto(-57479, -58568, -3319);
		gcall.Stepto(-57545, -58463, -3319);
		gcall.Stepto(-57610, -58357, -3315);
		gcall.Stepto(-57680, -58255, -3305);
		gcall.Stepto(-57751, -58154, -3288);
		gcall.Stepto(-57834, -58061, -3266);
		gcall.Stepto(-57925, -57977, -3243);
		gcall.Stepto(-58034, -57920, -3227);
		gcall.Stepto(-58140, -57880, -3215);
		gcall.NewSpend(1);
		Sleep(1000);
		gcall.FindThenKill(0, 1000, modeNormal | modeAoe | modePickupOnce | modeTask,2,303);
		Sleep(1000);
		break;
	case 3:
		gcall.NewSpend(2.5);
		gcall.Stepto(-58493, -58224, -3216,10,20,5000);
		gcall.Stepto(-59020, -57931, -3191,10,20,5000);
		gcall.Stepto(-59360, -57612, -3214);
		gcall.Stepto(-59388, -57548, -3216);
		gcall.Stepto(-59487, -57320, -3221);
		gcall.Stepto(-59583, -57093, -3220);
		gcall.Stepto(-59701, -56876, -3209);
		gcall.Stepto(-59812, -56692, -3190);
		gcall.Stepto(-59984, -56412, -3170);
		gcall.Stepto(-60208, -56044, -3171);
		gcall.Stepto(-60425, -55672, -3189);
		gcall.Stepto(-60629, -55286, -3202);
		gcall.Stepto(-60815, -54886, -3175);
		gcall.Stepto(-60988, -54488, -3155);
		gcall.Stepto(-61159, -54094, -3166);
		gcall.Stepto(-61328, -53696, -3175);
		gcall.Stepto(-61414, -53265, -3177);
		gcall.Stepto(-61469, -52835, -3162);
		gcall.Stepto(-61517, -52406, -3151);
		gcall.Stepto(-61486, -51988, -3137);
		gcall.Stepto(-61423, -51688, -3129);
		gcall.Stepto(-61424, -51440, -3122);
		gcall.Stepto(-61448, -51194, -3114);
		gcall.Stepto(-61521, -50959, -3105);
		gcall.Stepto(-61674, -50764, -3101);
		gcall.Stepto(-61886, -50639, -3097);
		gcall.Stepto(-62115, -50536, -3082);
		gcall.Stepto(-62347, -50449, -3066);
		gcall.Stepto(-62584, -50378, -3047);
		gcall.Stepto(-62835, -50350, -3038);
		gcall.Stepto(-63082, -50331, -3040);
		gcall.Stepto(-63330, -50316, -3058);
		gcall.Stepto(-63412, -50314, -3058);
		gcall.Stepto(-63538, -50290, -3055);
		gcall.Stepto(-63643, -50291, -3050);
		gcall.Stepto(-63966, -50297, -3042);
		gcall.Stepto(-64581, -50376, -3113);
		gcall.Stepto(-65079, -50534, -3169);
		gcall.Stepto(-65385, -50856, -3256);
		gcall.Stepto(-65469, -50906, -3256);
		gcall.NewSpend(1);
		Sleep(1000);
		gcall.DeliverQuests(303,taskid, L"고봉");
		Sleep(2000);
		break;
	case 4:
		gcall.Stepto(-63248, -50353, -3052);
		gcall.Stepto(-63420, -50368, -3053, 10, 10, 200);
		gcall.Stepto(-63595, -50384, -3048, 10, 10, 200);
		gcall.Stepto(-63781, -50401, -3052, 10, 10, 200);
		gcall.Stepto(-63966, -50418, -3061, 10, 10, 200);
		gcall.Stepto(-64151, -50434, -3084, 10, 10, 200);
		gcall.Stepto(-64336, -50451, -3116, 10, 10, 200);
		gcall.Stepto(-64521, -50471, -3146, 10, 10, 200);
		gcall.Stepto(-64702, -50512, -3161, 10, 10, 200);
		gcall.Stepto(-64861, -50608, -3183, 10, 10, 200);
		gcall.Stepto(-64994, -50736, -3210, 10, 10, 200);
		gcall.Stepto(-65159, -50792, -3229, 10, 10, 200);
		gcall.Stepto(-65340, -50833, -3251, 10, 10, 200);
		//从NPC走到打怪点
		gcall.Stepto(-65188, -50866, -3239);
		gcall.Stepto(-65035, -50944, -3236);
		gcall.Stepto(-64874, -51037, -3229);
		gcall.Stepto(-64711, -51127, -3236);

		Sleep(1000);
		gcall.FindThenKill(0, 500, modeNormal | modeAoe | modeTask,4);
		Sleep(1000);
		break;
	case 5:
		gcall.Stepto(-63285, -50357, -3053);
		gcall.Stepto(-63484, -50370, -3051, 10, 10, 200);
		gcall.Stepto(-63670, -50383, -3050, 10, 10, 200);
		gcall.Stepto(-63855, -50395, -3053, 10, 10, 200);
		gcall.Stepto(-64041, -50408, -3067, 10, 10, 200);
		gcall.Stepto(-64227, -50420, -3092, 10, 10, 200);
		gcall.Stepto(-64412, -50438, -3126, 10, 10, 200);
		gcall.Stepto(-64596, -50464, -3148, 10, 10, 200);
		gcall.Stepto(-64741, -50570, -3171, 10, 10, 200);
		gcall.Stepto(-64840, -50727, -3187, 10, 10, 200);
		gcall.Stepto(-64895, -50904, -3214, 10, 10, 200);
		gcall.Stepto(-64826, -51045, -3226, 10, 10, 200);


		//从打怪点走到门前
		gcall.Stepto(-64550, -51188, -3246);
		gcall.Stepto(-64656, -51336, -3248);
		gcall.Stepto(-64807, -51444, -3248);
		gcall.Stepto(-64937, -51578, -3252);
		gcall.Stepto(-65047, -51727, -3253);

		gcall.FindThenKill(0, 500, modeNormal | modeAoe | modeTask,5);
		Sleep(1000);
		break;
	case 6:
		
		gcall.Stepto(-63421, -50368, -3053);
		gcall.Stepto(-63580, -50378, -3049, 10, 10, 200);
		gcall.Stepto(-63765, -50397, -3052, 10, 10, 200);
		gcall.Stepto(-63949, -50419, -3060, 10, 10, 200);
		gcall.Stepto(-64133, -50450, -3084, 10, 10, 200);
		gcall.Stepto(-64315, -50487, -3114, 10, 10, 200);
		gcall.Stepto(-64496, -50530, -3141, 10, 10, 200);
		gcall.Stepto(-64677, -50574, -3163, 10, 10, 200);
		gcall.Stepto(-64834, -50670, -3184, 10, 10, 200);
		gcall.Stepto(-64943, -50819, -3213, 10, 10, 200);
		gcall.Stepto(-65021, -50988, -3238, 10, 10, 200);
		gcall.Stepto(-65064, -51169, -3253, 10, 10, 200);
		gcall.Stepto(-65076, -51354, -3259, 10, 10, 200);
		gcall.Stepto(-65071, -51540, -3253, 10, 10, 200);

		
		//从门前打怪点走到门前开门
		gcall.Stepto(-65055, -51726, -3253);
		Sleep(1000);
		gcall.Stepto(-64932, -51707, -3254);
		Sleep(1000);
		gcall.PickupTask(150);
		Sleep(1000);
		break;
	case 7:
		gcall.Stepto(-63344, -50355, -3055);
		gcall.Stepto(-63548, -50365, -3050, 10, 10, 200);
		gcall.Stepto(-63733, -50374, -3051, 10, 10, 200);
		gcall.Stepto(-63919, -50386, -3058, 10, 10, 200);
		gcall.Stepto(-64104, -50404, -3073, 10, 10, 200);
		gcall.Stepto(-64289, -50424, -3103, 10, 10, 200);
		gcall.Stepto(-64472, -50456, -3139, 10, 10, 200);
		gcall.Stepto(-64650, -50509, -3156, 10, 10, 200);
		gcall.Stepto(-64814, -50596, -3179, 10, 10, 200);
		gcall.Stepto(-64943, -50729, -3203, 10, 10, 200);
		gcall.Stepto(-65027, -50894, -3232, 10, 10, 200);
		gcall.Stepto(-65037, -51078, -3248, 10, 10, 200);
		gcall.Stepto(-65010, -51262, -3257, 10, 10, 200);
		gcall.Stepto(-64978, -51445, -3252, 10, 10, 100);
		gcall.Stepto(-64949, -51629, -3254, 10, 10, 50);
		//开门口走到NPC
		Sleep(1000);
		gcall.Stepto(-64858, -51740, -3253);
		Sleep(1000);
		gcall.DeliverQuests(303,taskid,L"도단하");
		Sleep(1000);
		break;
	case 8:
		//NPC走出来
		gcall.Stepto(-63344, -50355, -3055);
		gcall.Stepto(-63548, -50365, -3050, 10, 10, 200);
		gcall.Stepto(-63733, -50374, -3051, 10, 10, 200);
		gcall.Stepto(-63919, -50386, -3058, 10, 10, 200);
		gcall.Stepto(-64104, -50404, -3073, 10, 10, 200);
		gcall.Stepto(-64289, -50424, -3103, 10, 10, 200);
		gcall.Stepto(-64472, -50456, -3139, 10, 10, 200);
		gcall.Stepto(-64650, -50509, -3156, 10, 10, 200);
		gcall.Stepto(-64814, -50596, -3179, 10, 10, 200);
		gcall.Stepto(-64943, -50729, -3203, 10, 10, 200);
		gcall.Stepto(-65027, -50894, -3232, 10, 10, 200);
		gcall.Stepto(-65037, -51078, -3248, 10, 10, 200);
		gcall.Stepto(-65010, -51262, -3257, 10, 10, 200);
		gcall.Stepto(-64978, -51445, -3252, 10, 10, 200);
		gcall.Stepto(-64949, -51629, -3254, 10, 10, 200);
		gcall.Stepto(-65125, -51619, -3252);
		gcall.Stepto(-65070, -51781, -3252);
		gcall.Stepto(-65020, -51960, -3251);
		gcall.Stepto(-65169, -52070, -3247);
		gcall.Stepto(-65349, -52118, -3244);
		Sleep(1000);
		gcall.PickupTask(150);
		Sleep(15000);
		break;
	case 9:
		//NPC走出来
		gcall.Stepto(-63344, -50355, -3055);
		gcall.Stepto(-63263, -50339, -3053);
		gcall.Stepto(-63609, -50354, -3051);
		gcall.Stepto(-63978, -50398, -3059);
		gcall.Stepto(-65000, -50978, -3236);
		gcall.Stepto(-63928, -50456, -3056);
		gcall.Stepto(-64169, -50486, -3092);
		gcall.Stepto(-64390, -50614, -3132);
		gcall.Stepto(-64587, -50781, -3164);
		gcall.Stepto(-64709, -51010, -3217);
		gcall.Stepto(-64800, -51251, -3250);


		gcall.Stepto(-64887, -51484, -3249);
		gcall.Stepto(-64977, -51725, -3254);
		gcall.Stepto(-65069, -51972, -3249);
		gcall.Stepto(-65222, -52165, -3246);
		gcall.Stepto(-65449, -52282, -3269);

		Sleep(2000);
		gcall.FindThenKill(0, 1000, modeNormal | modeAoe | modePickup);
		Sleep(1000);
		gcall.Stepto(-65437, -52250, -3262);
		Sleep(1000);
		gcall.FollowNpc(L"도단하",1000);
		Sleep(500);
		gcall.DeliverQuests(303,taskid,L"도단하");
		Sleep(1000);
		break;
	case 10:
		gcall.CityConvey(1);
		Sleep(5000);
		gcall.WaitPlans();
		Sleep(2000);
		break;
	case 11:

		gcall.Stepto(-48903, -49643, -2378);
		gcall.Stepto(-48890, -49928, -2378);
		Sleep(1000);
		gcall.DeliverQuests(303, 0xb, L"고봉");
		Sleep(1000);
		break;
	case 12:
		gcall.NewSpend(2.5);
		Sleep(1000);
		gcall.Stepto(-49130, -49655, -2382);
		gcall.Stepto(-49673, -49564, -2386);
		gcall.Stepto(-50484, -49319, -2376);
		gcall.Stepto(-50873, -49109, -2346);
		gcall.Stepto(-50969, -48379, -2361);
		gcall.Stepto(-51551, -48169, -2362);
		gcall.Stepto(-52114, -48476, -2423);
		gcall.Stepto(-52467, -48808, -2610);
		gcall.Stepto(-52717, -48997, -2685);
		gcall.Stepto(-53149, -49092, -2665);
		gcall.Stepto(-53653, -49252, -2657);
		gcall.Stepto(-54233, -49620, -2702);
		gcall.Stepto(-54864, -50075, -2686);
		gcall.Stepto(-55346, -50354, -2646);
		gcall.Stepto(-55637, -50286, -2576);
		gcall.Stepto(-55891, -50194, -2539);
		gcall.Stepto(-56115, -50123, -2539);
		gcall.Stepto(-56089, -49929, -2539);
		gcall.NewSpend(1);
		Sleep(500);
		gcall.DeliverQuests(303, 0xc, L"도천풍");
		Sleep(10000);
		break;
	}
}

void TaskScript::Task_497(int taskid)
{
	switch (taskid)
	{
	case 1:
		gcall.DeliverQuests(497, taskid, L"남소유");
		Sleep(1000);
		break;
	case 2:
		gcall.DeliverQuests(497, 2, 0,1,0,1);
		Sleep(1000);
		gcall.NewBag();
		Sleep(6000);
		break;
	case 3:
		gcall.DeliverQuests(497, taskid, L"남소유");
		Sleep(1000);
		break;
	}
}
void TaskScript::Task_304(int taskid)
{
	switch (taskid)
	{
	case 1:
		gcall.NewSpend(2.5);
		Sleep(1000);
		gcall.Stepto(-56082, -50123, -2539);
		gcall.Stepto(-55741, -50245, -2576);
		gcall.Stepto(-55498, -50317, -2588);
		gcall.Stepto(-55043, -50360, -2687);
		gcall.Stepto(-54542, -50446, -2650);
		gcall.Stepto(-54321, -50467, -2611);
		gcall.Stepto(-53996, -50461, -2525);
		gcall.Stepto(-53781, -50473, -2525);
		gcall.NewSpend(1);
		Sleep(1000);
		gcall.DeliverQuests(304,taskid, L"곽대규");
		Sleep(1000);
		
		break;
	case 2:
		gcall.NewSpend(2.5);
		Sleep(1000);
		gcall.Stepto(-54066, -50475, -2541);
		gcall.Stepto(-54336, -50473, -2610);
		gcall.Stepto(-54513, -50472, -2641);
		gcall.Stepto(-54940, -50471, -2689);
		gcall.Stepto(-55396, -51015, -2681);
		gcall.Stepto(-55498, -51218, -2668);
		gcall.NewSpend(1);
		Sleep(1000);
		/*支线任务*/
		gcall.NPCJieRenWu(6, 0x40070, 0x551, 0, 0);
		Sleep(1000);
		gcall.NPCJieRenWu(6, 0x40070, 0x141, 0, 0);
		Sleep(1000);
		gcall.DeliverQuests(0x141, 1, 0, 0, 0, 1);
		Sleep(1000);
		gcall.DeliverQuests(0x141, 2, 0, 0, 0, 1);
		Sleep(1000);
		gcall.DeliverQuests(0x141, 3, 0, 0, 0, 1);
		Sleep(1000);
		gcall.DeliverQuests(0x141, 4, 0, 0, 0, 1);
		Sleep(1000);
		gcall.DeliverQuests(0x551, 1, 0, 0, 0, 1);
		Sleep(1000);
		gcall.DeliverQuests(0x551, 2, 0, 1);
		Sleep(1000);
		/*支线任务结束*/

		gcall.Stepto(-55027, -51563, -2696);
		gcall.Stepto(-54728, -51878, -2663);
		Sleep(1000);
		gcall.NPCJieRenWu(3, 0x40070, 0x142, 0, 0);
		Sleep(1000);
		gcall.Stepto(-54493, -51651, -2699);
		gcall.Stepto(-54314, -51487, -2691);
		//Sleep(500);
		//gcall.NPCJieRenWu(4, 0x40070, 0x145, 0, 0);//这个任务没了。
		//Sleep(1000);
		gcall.NewSpend(2.5);
		gcall.Stepto(-53906, -51759, -2696);
		gcall.Stepto(-53194, -51861, -2713);
		gcall.Stepto(-52313, -52215, -2683);
		gcall.Stepto(-52254, -52698, -2695);
		gcall.Stepto(-52230, -53469, -2939);
		gcall.Stepto(-52127, -54449, -3051);
		gcall.Stepto(-51541, -54664, -3056);
		gcall.Stepto(-51074, -54863, -3051);
		gcall.Stepto(-50549, -55032, -3022);
		gcall.Stepto(-50451, -54997, -3022);
		gcall.NewSpend(1);
		Sleep(1000);
		gcall.DeliverQuests(0x141, 5, L"장호엄");
		Sleep(1000);
		gcall.NewSpend(2.5);
		gcall.Stepto(-50801, -54914, -3041);
		gcall.Stepto(-51127, -54696, -3049);
		gcall.Stepto(-51180, -54431, -3030);
		gcall.Stepto(-50962, -54353, -3012);
		gcall.Stepto(-50762, -54238, -3012);
		gcall.Stepto(-50534, -54127, -2988);
		gcall.NewSpend(1);
		Sleep(1000);
		gcall.DeliverQuests(304,taskid, L"곽준");
		Sleep(1000);
		
		break;
	case 3:
		Sleep(1000);
		gcall.Stepto(-50720, -54076, -3012);
		gcall.Stepto(-50788, -53991, -2980);
		Sleep(1000);
		gcall.DeliverQuests(304,taskid, L"곽칠");
		Sleep(1000);
		break;
	case 4:
		gcall.Stepto(-50643, -54114, -3012);
		gcall.Stepto(-50509, -54148, -2988);
		Sleep(1000);
		gcall.DeliverQuests(304,taskid, L"곽준");
		Sleep(1000);
		gcall.WearEquipment(L"홍문도끼 1단계", 1);
		Sleep(1000);
		gcall.HeChengWuQiByHun(EQUITMENT_POS::WUQI);
		Sleep(1000);
		break;
	case 5:
		gcall.NewSpend(2.5);
		gcall.Stepto(-50631, -54188, -3012);
		gcall.Stepto(-50706, -54222, -3012);
		gcall.Stepto(-50928, -54332, -3012);
		gcall.Stepto(-51009, -54372, -3021);
		gcall.Stepto(-51139, -54438, -3030);
		gcall.Stepto(-51362, -54550, -3043);
		gcall.Stepto(-51591, -54633, -3054);
		gcall.Stepto(-51833, -54694, -3053);
		gcall.Stepto(-52070, -54767, -3043);
		gcall.Stepto(-52206, -54968, -3045);
		gcall.Stepto(-52207, -55211, -3054);
		gcall.Stepto(-52181, -55459, -3082);
		gcall.Stepto(-52155, -55705, -3144);
		gcall.Stepto(-52129, -55952, -3139);
		gcall.Stepto(-52124, -56202, -3137);
		gcall.Stepto(-52145, -56449, -3140);
		gcall.Stepto(-52167, -56696, -3172);
		gcall.Stepto(-52190, -56939, -3207);
		gcall.Stepto(-52213, -57187, -3219);
		gcall.Stepto(-52236, -57435, -3226);
		gcall.Stepto(-52253, -57682, -3225);
		gcall.Stepto(-52234, -57930, -3247);
		gcall.Stepto(-52223, -58179, -3250);
		gcall.Stepto(-52213, -58427, -3258);
		gcall.Stepto(-52209, -58516, -3263);
		gcall.NewSpend(1);
		//gcall.randXianlu();
		Sleep(1000);
		gcall.FindThenKill(0, 300, modeNormal | modeAoe | modePickup);
		gcall.NewSpend(2.5);
		gcall.Stepto(-52208, -58519, -3263);
		gcall.Stepto(-52027, -58674, -3259);
		gcall.Stepto(-51804, -58784, -3273);
		gcall.Stepto(-51581, -58895, -3283);
		gcall.Stepto(-51360, -59004, -3275);
		gcall.Stepto(-51139, -59119, -3274);
		gcall.Stepto(-50919, -59234, -3274);
		gcall.Stepto(-50717, -59342, -3273);
		gcall.Stepto(-50717, -59343, -3273);
		gcall.NewSpend(1);
		gcall.FindThenKill(0, 300, modeNormal | modeAoe | modePickup);
		gcall.NewSpend(2.5);
		gcall.Stepto(-50657, -59441, -3276);
		gcall.Stepto(-50547, -59663, -3271);
		gcall.Stepto(-50396, -59859, -3267);
		gcall.Stepto(-50193, -60004, -3268);
		gcall.Stepto(-49998, -60157, -3286);
		gcall.Stepto(-49803, -60310, -3301);
		gcall.Stepto(-49781, -60327, -3302);
		gcall.NewSpend(1);
		gcall.FindThenKill(0, 300, modeNormal | modeAoe | modePickup);
		gcall.NewSpend(2.5);
		gcall.Stepto(-49819, -60343, -3301);
		gcall.Stepto(-50007, -60502, -3299);
		gcall.Stepto(-50182, -60677, -3304);
		gcall.Stepto(-50360, -60849, -3312);
		gcall.Stepto(-50539, -61021, -3317);
		gcall.Stepto(-50651, -61129, -3319);
		gcall.NewSpend(1);
		gcall.FindThenKill(0, 300, modeNormal | modeAoe | modePickup);
		gcall.NewSpend(2.5);
		gcall.Stepto(-50714, -61065, -3311);
		gcall.Stepto(-50923, -60936, -3305);
		gcall.Stepto(-51138, -60811, -3300);
		gcall.Stepto(-51352, -60686, -3319);
		gcall.Stepto(-51507, -60595, -3332);
		gcall.NewSpend(1);
		gcall.FindThenKill(0, 300, modeNormal | modeAoe | modePickup);
		gcall.NewSpend(2.5);
		gcall.Stepto(-51516, -60689, -3324);
		gcall.Stepto(-51541, -60934, -3325);
		gcall.Stepto(-51572, -61180, -3331);
		gcall.Stepto(-51590, -61322, -3337);
		gcall.NewSpend(1);
		gcall.FindThenKill(0, 300, modeNormal | modeAoe | modePickup);
		gcall.NewSpend(2.5);
		gcall.Stepto(-51620, -61275, -3335);
		gcall.Stepto(-51626, -61285, -3336);
		gcall.Stepto(-51694, -61396, -3343);
		gcall.NewSpend(1);
		Sleep(1000);
		gcall.PickupTask();
		gcall.NewSpend(2.5);
		gcall.Stepto(-51692, -61392, -3343);
		gcall.Stepto(-51720, -61375, -3341);
		gcall.Stepto(-51920, -61229, -3339);
		gcall.Stepto(-52107, -61067, -3336);
		gcall.Stepto(-52294, -60904, -3328);
		gcall.Stepto(-52442, -60774, -3324);
		gcall.NewSpend(1);
		gcall.FindThenKill(0, 300, modeNormal | modeAoe | modePickup);
		gcall.NewSpend(2.5);
		gcall.Stepto(-52467, -60848, -3325);
		gcall.Stepto(-52546, -61083, -3332);
		gcall.Stepto(-52625, -61318, -3342);
		gcall.Stepto(-52642, -61368, -3345);
		gcall.NewSpend(1);
		Sleep(1000);
		gcall.PickupTask();

		gcall.Stepto(-52711, -61365, -3346);
		gcall.Stepto(-52792, -61166, -3336);
		gcall.Stepto(-52890, -60939, -3330);
		gcall.Stepto(-52945, -60812, -3318);
		Sleep(1000);
		gcall.PickupTask();
		gcall.Stepto(-53065, -60747, -3315);
		gcall.Stepto(-53292, -60647, -3314);
		gcall.Stepto(-53525, -60562, -3319);
		gcall.Stepto(-53755, -60479, -3324);
		gcall.Stepto(-53989, -60395, -3323);
		gcall.Stepto(-54225, -60326, -3321);
		gcall.Stepto(-54433, -60246, -3321);
		gcall.Stepto(-54458, -60180, -3316);

		gcall.NewSpend(1);
		Sleep(1000);
		gcall.FindThenKill(0, 1000, modeNormal | modeAoe | modeGoback | modePickupOnce | modeTask |modePickup,5);

		Sleep(1000);
		break;
	case 6:
		
		gcall.NewSpend(2.5);
		gcall.Stepto(-53830, -60057, -3298);
		gcall.Stepto(-54066, -60133, -3308);
		gcall.Stepto(-54303, -60205, -3316);
		gcall.Stepto(-54545, -60262, -3324);
		gcall.Stepto(-54787, -60313, -3328);
		gcall.Stepto(-55027, -60322, -3328);
		gcall.Stepto(-55284, -60317, -3329);
		gcall.Stepto(-55532, -60319, -3329);
		gcall.Stepto(-55776, -60297, -3329);
		gcall.Stepto(-55844, -60291, -3329);
		gcall.NewSpend(1);
		Sleep(1000);
		gcall.PickupTask(1500,322,1);
		gcall.NewSpend(2.5);
		gcall.Stepto(-56004, -60166, -3323);
		gcall.Stepto(-55996, -59942, -3317);
		gcall.Stepto(-55782, -59810, -3320);
		gcall.Stepto(-55570, -59682, -3319);
		gcall.Stepto(-55358, -59553, -3312);
		gcall.Stepto(-55123, -59551, -3310);
		gcall.Stepto(-54887, -59618, -3311);
		gcall.Stepto(-54649, -59687, -3308);
		gcall.Stepto(-54414, -59765, -3299);
		gcall.Stepto(-54180, -59846, -3287);
		gcall.Stepto(-53944, -59928, -3291);
		gcall.Stepto(-53710, -60009, -3295);
		gcall.Stepto(-53465, -60040, -3293);
		gcall.Stepto(-53231, -59966, -3293);
		gcall.Stepto(-53070, -59782, -3292);
		gcall.Stepto(-52962, -59558, -3287);
		gcall.Stepto(-52869, -59329, -3278);
		gcall.Stepto(-52793, -59092, -3264);
		gcall.Stepto(-52718, -58855, -3263);
		gcall.Stepto(-52645, -58624, -3268);
		gcall.Stepto(-52573, -58382, -3265);
		gcall.Stepto(-52516, -58140, -3262);
		gcall.Stepto(-52468, -57937, -3251);
		gcall.Stepto(-52455, -57869, -3246);
		gcall.Stepto(-52407, -57625, -3230);
		gcall.Stepto(-52361, -57390, -3224);
		gcall.Stepto(-52314, -57146, -3220);
		gcall.Stepto(-52266, -56903, -3207);
		gcall.Stepto(-52236, -56746, -3185);
		gcall.Stepto(-52215, -56506, -3147);
		gcall.Stepto(-52196, -56263, -3137);
		gcall.Stepto(-52177, -56013, -3138);
		gcall.Stepto(-52162, -55765, -3143);
		gcall.Stepto(-52147, -55517, -3107);
		gcall.Stepto(-52133, -55269, -3060);
		gcall.Stepto(-52129, -55023, -3047);
		gcall.Stepto(-52130, -54773, -3042);
		gcall.Stepto(-52119, -54713, -3043);
		gcall.Stepto(-51883, -54637, -3052);
		gcall.Stepto(-51642, -54576, -3052);
		gcall.Stepto(-51396, -54531, -3042);
		gcall.Stepto(-51283, -54497, -3038);
		gcall.Stepto(-51057, -54399, -3031);
		gcall.Stepto(-50964, -54354, -3012);
		gcall.Stepto(-50844, -54294, -3012);
		gcall.Stepto(-50624, -54180, -3012);
		gcall.Stepto(-50567, -54150, -3012);
		gcall.NewSpend(1);
		Sleep(1000);
		gcall.DeliverQuests(304,taskid, L"곽준");
		Sleep(1000);
		break;
	case 7:
		gcall.NewSpend(2.5);
		gcall.Stepto(-51003, -54389, -3022);
		gcall.Stepto(-51338, -54526, -3041);
		gcall.Stepto(-51873, -54531, -3054);
		gcall.Stepto(-52178, -54011, -3037);
		gcall.Stepto(-52194, -53110, -2826);
		gcall.Stepto(-52272, -52330, -2677);
		gcall.Stepto(-52383, -51933, -2710);
		gcall.Stepto(-53169, -51828, -2723);
		gcall.Stepto(-53767, -51724, -2693);
		gcall.Stepto(-54154, -51761, -2698);
		gcall.Stepto(-54620, -51806, -2684);
		gcall.Stepto(-54747, -51886, -2661);
		gcall.NewSpend(1);
		Sleep(1000);
		gcall.DeliverQuests(0x142,2, L"한미백");
		Sleep(1000);
		gcall.DeliverQuests(322,3,NULL,0,0,1);
		Sleep(1000);
		gcall.DeliverQuests(322,4,L"한미백");
		Sleep(1000);
		gcall.NewSpend(2.5);
		Sleep(1000);
		gcall.Stepto(-54802, -51763, -2676);
		gcall.Stepto(-54850, -51665, -2688);
		gcall.Stepto(-54903, -51553, -2703);
		gcall.Stepto(-54956, -51441, -2707);
		gcall.Stepto(-55009, -51329, -2706);
		gcall.Stepto(-55062, -51217, -2705);
		gcall.Stepto(-55115, -51105, -2705);
		gcall.Stepto(-55168, -50993, -2702);
		gcall.Stepto(-55221, -50881, -2699);
		gcall.Stepto(-55275, -50769, -2689);
		gcall.Stepto(-55328, -50657, -2675);
		gcall.Stepto(-55381, -50545, -2655);
		gcall.Stepto(-55434, -50432, -2629);
		gcall.Stepto(-55485, -50325, -2593);
		gcall.Stepto(-55592, -50289, -2576);
		gcall.Stepto(-55711, -50252, -2576);
		gcall.Stepto(-55830, -50214, -2540);
		gcall.Stepto(-55961, -50173, -2539);
		gcall.Stepto(-56081, -50137, -2539);
		gcall.Stepto(-56130, -50006, -2539);
		gcall.Stepto(-56104, -49893, -2539);
		gcall.NewSpend(1);
		gcall.DeliverQuests(304, taskid, L"도천풍");
		Sleep(1000);
		break;
	case 8:
		gcall.DeliverQuests(304,taskid, NULL, 1,0, 1);
		Sleep(1000);
		break;
	case 9:
		gcall.DeliverQuests(304, taskid, L"도천풍");
		gcall.NewBag();
		Sleep(5000);
		break;
	case 10:
		gcall.NewSpend(2.5);
		gcall.Stepto(-56089, -50109, -2539);
		gcall.Stepto(-55886, -50178, -2539);
		gcall.Stepto(-55677, -50242, -2576);
		gcall.Stepto(-55625, -50257, -2576);
		gcall.Stepto(-55392, -50324, -2635);
		gcall.Stepto(-55349, -50336, -2644);
		gcall.Stepto(-55157, -50230, -2669);
		gcall.Stepto(-54956, -50084, -2683);
		gcall.Stepto(-54764, -49953, -2688);
		gcall.Stepto(-54569, -49819, -2693);
		gcall.Stepto(-54277, -49623, -2700);
		gcall.Stepto(-53913, -49381, -2672);
		gcall.Stepto(-53666, -49230, -2653);
		gcall.Stepto(-53632, -49221, -2655);
		gcall.Stepto(-53218, -49103, -2671);
		gcall.Stepto(-52791, -48998, -2674);
		gcall.Stepto(-52593, -48949, -2680);
		gcall.Stepto(-52520, -48887, -2646);
		gcall.Stepto(-52197, -48597, -2455);
		gcall.Stepto(-51885, -48317, -2390);
		gcall.Stepto(-51715, -48178, -2369);
		gcall.Stepto(-51535, -47979, -2342);
		gcall.Stepto(-51448, -47693, -2301);
		gcall.Stepto(-51393, -47441, -2268);
		gcall.NewSpend(1);
		Sleep(5000);
		gcall.Stepto(-51339, -47216, -2258);
		gcall.WaitPlans();
		gcall.Stepto(-51271, -47025, -2249);
		gcall.WaitPlans();
		gcall.Stepto(-51127, -46616, -2211);
		gcall.WaitPlans();
		gcall.NewSpend(2.5);
		gcall.Stepto(-51064, -46385, -2214);
		gcall.Stepto(-51006, -46144, -2222);
		gcall.Stepto(-50869, -45903, -2234);
		gcall.Stepto(-50544, -45614, -2237);
		gcall.Stepto(-50361, -45563, -2236);
		gcall.Stepto(-49949, -45437, -2239);
		gcall.Stepto(-49657, -45281, -2243);
		gcall.Stepto(-49490, -45027, -2250);
		gcall.Stepto(-49323, -44679, -2247);
		gcall.Stepto(-49324, -44626, -2247);
		gcall.Stepto(-49334, -44184, -2239);
		gcall.Stepto(-49441, -43850, -2231);
		gcall.Stepto(-49632, -43664, -2222);
		gcall.Stepto(-49807, -43599, -2200);
		gcall.Stepto(-50158, -43505, -2196);
		gcall.Stepto(-50396, -43442, -2187);
		gcall.Stepto(-50550, -43400, -2191);
		gcall.Stepto(-50664, -43363, -2195);
		gcall.Stepto(-50898, -43289, -2191);
		gcall.Stepto(-51136, -43207, -2187);
		gcall.Stepto(-51364, -43121, -2184);
		gcall.Stepto(-51597, -43016, -2173);
		gcall.Stepto(-51751, -42844, -2182);
		gcall.Stepto(-51831, -42625, -2189);
		gcall.Stepto(-51814, -42359, -2196);
		gcall.Stepto(-51748, -42114, -2202);
		gcall.Stepto(-51649, -41884, -2218);
		gcall.Stepto(-51538, -41662, -2223);
		gcall.Stepto(-51418, -41443, -2237);
		gcall.NewSpend(1);
		Sleep(5000);
		gcall.Stepto(-51371, -41358, -2243);
		gcall.WaitPlans();
		gcall.Stepto(-51346, -41321, -2241);
		gcall.WaitPlans();
		gcall.Stepto(-51093, -40956, -2234);
		gcall.WaitPlans();
		gcall.NewSpend(2.5);
		gcall.Stepto(-50856, -40596, -2238);
		gcall.Stepto(-50731, -40391, -2237);
		gcall.Stepto(-50527, -40001, -2242);
		gcall.Stepto(-50421, -39723, -2247);
		gcall.Stepto(-50329, -39349, -2266);
		gcall.Stepto(-50223, -38922, -2275);
		gcall.Stepto(-50117, -38501, -2264);
		gcall.Stepto(-50011, -38077, -2253);
		gcall.Stepto(-49956, -37856, -2247);
		gcall.Stepto(-50034, -37509, -2235);
		gcall.Stepto(-50124, -37088, -2183);
		gcall.Stepto(-50210, -36658, -2129);
		gcall.Stepto(-50237, -36435, -2150);
		gcall.Stepto(-50274, -36099, -2159);
		gcall.Stepto(-50302, -35849, -2174);
		gcall.Stepto(-50330, -35600, -2181);
		gcall.Stepto(-50358, -35350, -2207);
		gcall.Stepto(-50385, -35103, -2238);
		gcall.Stepto(-50413, -34857, -2271);
		gcall.Stepto(-50441, -34607, -2297);
		gcall.Stepto(-50469, -34358, -2285);
		gcall.Stepto(-50497, -34108, -2276);
		gcall.Stepto(-50525, -33861, -2267);
		gcall.Stepto(-50552, -33611, -2241);
		gcall.Stepto(-50586, -33363, -2230);
		gcall.Stepto(-50653, -32930, -2212);
		gcall.Stepto(-50721, -32502, -2155);
		gcall.Stepto(-50760, -32255, -2094);
		gcall.Stepto(-50846, -31931, -1976);
		gcall.Stepto(-50828, -31617, -1943);
		gcall.Stepto(-50640, -31379, -1944);
		gcall.Stepto(-50319, -31450, -1963);
		gcall.NewSpend(1);
		Sleep(1000);
		gcall.DeliverQuests(304,0xA,L"공삼식");
		Sleep(1000);
		break;
	}

}

void TaskScript::Task_305(int taskid)
{
	switch (taskid)
	{
	case 1:
		gcall.NewSpend(2.5);
		gcall.Stepto(-50772, -31235, -1944);
		gcall.Stepto(-50766, -31313, -1944);
		gcall.Stepto(-50747, -31560, -1944);
		gcall.Stepto(-50728, -31807, -1966);
		gcall.Stepto(-50710, -32056, -2031);
		gcall.Stepto(-50690, -32304, -2121);
		gcall.Stepto(-50672, -32550, -2169);
		gcall.Stepto(-50652, -32797, -2199);
		gcall.Stepto(-50633, -33044, -2223);
		gcall.Stepto(-50618, -33292, -2230);
		gcall.Stepto(-50610, -33536, -2234);
		gcall.Stepto(-50658, -33784, -2240);
		gcall.Stepto(-50721, -34022, -2255);
		gcall.Stepto(-50783, -34262, -2265);
		gcall.Stepto(-50910, -34473, -2266);
		gcall.Stepto(-51056, -34674, -2274);
		gcall.Stepto(-51192, -34881, -2284);
		gcall.Stepto(-51326, -35086, -2290);
		gcall.Stepto(-51508, -35254, -2300);
		gcall.Stepto(-51742, -35329, -2308);
		gcall.Stepto(-51989, -35344, -2318);
		gcall.Stepto(-52236, -35327, -2316);
		gcall.Stepto(-52484, -35310, -2302);
		gcall.Stepto(-52734, -35293, -2283);
		gcall.Stepto(-52981, -35276, -2260);
		gcall.Stepto(-53229, -35277, -2235);
		gcall.Stepto(-53477, -35285, -2201);
		gcall.Stepto(-53725, -35287, -2168);
		gcall.Stepto(-53974, -35295, -2171);
		gcall.Stepto(-54218, -35295, -2332);
		gcall.Stepto(-54470, -35293, -2508);
		gcall.Stepto(-54714, -35339, -2629);
		gcall.Stepto(-54954, -35392, -2692);
		gcall.Stepto(-55184, -35307, -2784);
		gcall.Stepto(-55357, -35131, -2838);
		gcall.Stepto(-55479, -34918, -2855);
		gcall.Stepto(-55528, -34675, -2900);
		gcall.Stepto(-55470, -34436, -2926);
		gcall.Stepto(-55319, -34239, -2931);
		gcall.Stepto(-55134, -34075, -2925);
		gcall.Stepto(-54905, -34023, -2964);
		gcall.Stepto(-54699, -34160, -3063);
		gcall.Stepto(-54525, -34338, -3161);
		gcall.Stepto(-54413, -34558, -3207);
		gcall.Stepto(-54355, -34799, -3270);
		gcall.Stepto(-54357, -35044, -3347);
		gcall.Stepto(-54490, -35252, -3419);
		gcall.Stepto(-54678, -35414, -3470);
		gcall.Stepto(-54908, -35382, -3501);
		gcall.Stepto(-55126, -35263, -3593);
		gcall.Stepto(-55304, -35098, -3674);
		gcall.Stepto(-55369, -34859, -3801);
		gcall.Stepto(-55358, -34611, -3861);
		gcall.Stepto(-55225, -34407, -3863);
		gcall.Stepto(-55044, -34238, -3861);
		gcall.Stepto(-54852, -34081, -3853);
		gcall.Stepto(-54680, -33904, -3857);
		gcall.Stepto(-54580, -33681, -3864);
		gcall.Stepto(-54555, -33625, -3864);
		gcall.Stepto(-54430, -33408, -3863);
		gcall.Stepto(-54246, -33254, -3863);
		gcall.Stepto(-54004, -33185, -3864);
		gcall.Stepto(-53757, -33155, -3865);
		gcall.Stepto(-53511, -33137, -3870);
		gcall.Stepto(-53479, -33135, -3871);
		gcall.NewSpend(1);
		Sleep(1000);
		gcall.DeliverQuests(305,taskid, L"곽대규");
		Sleep(1000);
		break;
	case 2:
		//gcall.NewSpend(2.5);
		//gcall.Stepto(-53473, -33136, -3871);
		//gcall.Stepto(-53583, -33119, -3869);
		//gcall.Stepto(-53833, -33083, -3869);
		//gcall.Stepto(-54076, -33085, -3870);
		//gcall.Stepto(-54312, -33157, -3868);
		//gcall.Stepto(-54493, -33324, -3867);
		//gcall.Stepto(-54605, -33543, -3866);
		//gcall.Stepto(-54645, -33712, -3862);
		//gcall.Stepto(-54672, -33832, -3859);
		//gcall.Stepto(-54710, -33996, -3857);
		//gcall.Stepto(-54880, -34143, -3858);
		//gcall.Stepto(-55062, -34307, -3861);
		//gcall.Stepto(-55235, -34488, -3863);
		//gcall.Stepto(-55381, -34686, -3854);
		//gcall.Stepto(-55394, -34770, -3831);
		//gcall.Stepto(-55408, -34986, -3737);
		//gcall.Stepto(-55386, -35009, -3727);
		//gcall.Stepto(-55211, -35189, -3624);
		//gcall.Stepto(-55044, -35360, -3528);
		//gcall.Stepto(-54897, -35512, -3464);
		//gcall.Stepto(-54800, -35475, -3474);
		//gcall.Stepto(-54675, -35428, -3468);
		//gcall.Stepto(-54585, -35329, -3452);
		//gcall.Stepto(-54418, -35142, -3378);
		//gcall.Stepto(-54273, -34980, -3310);
		//gcall.Stepto(-54290, -34920, -3297);
		//gcall.Stepto(-54363, -34682, -3240);
		//gcall.Stepto(-54436, -34446, -3179);
		//gcall.Stepto(-54479, -34307, -3157);
		//gcall.Stepto(-54560, -34254, -3145);
		//gcall.Stepto(-54776, -34114, -3006);
		//gcall.Stepto(-54882, -34045, -2974);
		//gcall.Stepto(-54901, -34049, -2971);
		//gcall.Stepto(-55142, -34108, -2925);
		//gcall.Stepto(-55199, -34122, -2918);
		//gcall.Stepto(-55262, -34199, -2916);
		//gcall.Stepto(-55416, -34394, -2938);
		//gcall.Stepto(-55555, -34572, -2908);
		//gcall.NewSpend(1);
		//gcall.Stepto(-55547, -34635, -2906);
		//gcall.Stepto(-55533, -34741, -2896);
		//gcall.Stepto(-55493, -34984, -2834);
		//gcall.Stepto(-55490, -34991, -2832);
		//gcall.Stepto(-55321, -35169, -2833);
		//gcall.Stepto(-55150, -35348, -2766);
		//gcall.Stepto(-55071, -35431, -2729);
		//gcall.Stepto(-55011, -35417, -2713);
		//gcall.Stepto(-54786, -35363, -2655);
		//gcall.Stepto(-54785, -35363, -2655);
		//gcall.Stepto(-54570, -35266, -2562);
		//gcall.Stepto(-54471, -35221, -2509);
		//gcall.Stepto(-54361, -35216, -2441);
		//gcall.Stepto(-54259, -35212, -2377);
		//gcall.Stepto(-54180, -35283, -2307);
		//gcall.Stepto(-54145, -35312, -2274);
		//gcall.Stepto(-54129, -35325, -2254);
		//gcall.Stepto(-54020, -35319, -2191);
		//gcall.Stepto(-53772, -35305, -2166);
		//gcall.Stepto(-53525, -35291, -2194);
		//gcall.Stepto(-53277, -35277, -2229);
		//gcall.Stepto(-53034, -35268, -2256);
		//gcall.Stepto(-52963, -35263, -2263);
		//gcall.NewSpend(2.5);
		//gcall.Stepto(-52815, -35252, -2279);
		//gcall.Stepto(-52571, -35234, -2295);
		//gcall.Stepto(-52323, -35219, -2311);
		//gcall.Stepto(-52075, -35205, -2328);
		//gcall.Stepto(-51829, -35163, -2314);
		//gcall.Stepto(-51600, -35076, -2304);
		//gcall.Stepto(-51370, -34980, -2298);
		//gcall.Stepto(-51169, -34837, -2282);
		//gcall.Stepto(-51019, -34639, -2273);
		//gcall.Stepto(-50886, -34434, -2264);
		//gcall.Stepto(-50750, -34221, -2266);
		//gcall.Stepto(-50697, -33979, -2252);
		//gcall.Stepto(-50658, -33735, -2237);
		//gcall.Stepto(-50635, -33488, -2234);
		//gcall.Stepto(-50632, -33240, -2230);
		//gcall.Stepto(-50637, -32993, -2218);
		//gcall.Stepto(-50661, -32746, -2193);
		//gcall.Stepto(-50700, -32501, -2159);
		//gcall.Stepto(-50739, -32256, -2096);
		//gcall.Stepto(-50778, -32011, -2006);
		//gcall.Stepto(-50812, -31766, -1953);
		//gcall.Stepto(-50745, -31532, -1944);
		//gcall.Stepto(-50656, -31398, -1944);
		//gcall.Stepto(-50445, -31446, -1954);
		//gcall.Stepto(-50349, -31507, -1961);
		//gcall.NewSpend(1);
		gcall.CityConvey(0x45);//传送过来
		Sleep(1000);
		gcall.WaitPlans();
		Sleep(2000);
		gcall.DeliverQuests(305,taskid, L"공삼식");
		Sleep(1000);
		break;
	case 3:
		gcall.NewSpend(2.5);
		gcall.Stepto(-50337, -31504, -1961);
		gcall.Stepto(-50425, -31444, -1955);
		gcall.Stepto(-50631, -31306, -1944);
		gcall.Stepto(-50837, -31167, -1943);
		gcall.Stepto(-51043, -31029, -1936);
		gcall.Stepto(-51242, -30882, -1912);
		gcall.Stepto(-51316, -30815, -1904);
		gcall.Stepto(-51379, -30753, -1905);
		gcall.Stepto(-51334, -30523, -1905);
		gcall.Stepto(-51328, -30430, -1905);
		gcall.NewSpend(1);
		Sleep(1000);
		gcall.DeliverQuests(305,taskid, L"도단하");
		Sleep(1000);
		break;
	case 4:
		gcall.DeliverQuests(305,taskid, L"남소유");
		Sleep(1000);
		break;
	}

}

void TaskScript::Task_306(int taskid)
{
	switch (taskid)
	{
	case 1:
		gcall.Stepto(-51392, -30549, -1905 ,10,20,200);
		gcall.Stepto(-51454, -30650, -1905, 10, 20, 200);
		gcall.Stepto(-51374, -30747, -1905, 10, 20, 200);
		gcall.Stepto(-51285, -30837, -1904, 10, 20, 200);
		gcall.Stepto(-51206, -30919, -1928, 10, 20, 200);
		gcall.Stepto(-51128, -31026, -1931, 10, 20, 200);
		gcall.Stepto(-51077, -31139, -1937, 10, 20, 200);
		gcall.Stepto(-51023, -31251, -1939, 10, 20, 200);
		gcall.Stepto(-50975, -31366, -1939, 10, 20, 200);
		Sleep(500);
		gcall.NPCJieRenWu(0xAF, 0x4006d, 0x150,0,0);
		Sleep(500);
		gcall.Stepto(-50813, -31294, -1944);
		gcall.Stepto(-50782, -31174, -1944);
		gcall.Stepto(-50749, -31055, -1944);
		gcall.Stepto(-50717, -30935, -1950);
		gcall.Stepto(-50688, -30814, -1945);
		Sleep(1000);
		gcall.BuyItem(8, 0, L"모팔모");
		gcall.KeyPress(27);
		Sleep(300);
		gcall.KeyPress(27);
		Sleep(1000);
		gcall.NewSpend(2.5);
		gcall.Stepto(-50657, -31212, -1944);
		gcall.Stepto(-50416, -31179, -1958);
		gcall.Stepto(-50165, -31144, -1993);
		gcall.Stepto(-49921, -31110, -2047);
		gcall.Stepto(-49677, -31137, -2116);
		gcall.Stepto(-49464, -31258, -2208);
		gcall.Stepto(-49306, -31449, -2278);
		gcall.Stepto(-49166, -31653, -2323);
		gcall.Stepto(-49025, -31857, -2338);
		gcall.Stepto(-48885, -32061, -2335);
		gcall.Stepto(-48745, -32266, -2332);
		gcall.Stepto(-48603, -32472, -2327);
		gcall.Stepto(-48463, -32676, -2326);
		gcall.Stepto(-48323, -32880, -2326);
		gcall.Stepto(-48182, -33086, -2338);
		gcall.Stepto(-48043, -33287, -2352);
		gcall.Stepto(-47848, -33443, -2375);
		gcall.Stepto(-47649, -33587, -2396);
		gcall.Stepto(-47447, -33734, -2399);
		gcall.Stepto(-47247, -33879, -2384);
		gcall.Stepto(-47045, -34025, -2371);
		gcall.Stepto(-46843, -34171, -2368);
		gcall.Stepto(-46644, -34316, -2378);
		gcall.Stepto(-46443, -34461, -2379);
		gcall.Stepto(-46243, -34607, -2361);
		gcall.Stepto(-46042, -34752, -2338);
		gcall.Stepto(-45829, -34883, -2315);
		gcall.Stepto(-45614, -35007, -2297);
		gcall.Stepto(-45403, -35132, -2261);
		gcall.Stepto(-45232, -35313, -2277);
		gcall.Stepto(-45075, -35505, -2295);
		gcall.Stepto(-44918, -35698, -2267);
		gcall.Stepto(-44731, -35854, -2237);
		gcall.Stepto(-44502, -35952, -2212);
		gcall.Stepto(-44263, -35983, -2174);
		gcall.Stepto(-44021, -35917, -2124);
		gcall.Stepto(-43782, -35849, -2092);
		gcall.Stepto(-43544, -35781, -2054);
		gcall.Stepto(-43305, -35713, -2005);
		gcall.Stepto(-43089, -35651, -1980);
		gcall.Stepto(-42827, -35576, -1925);
		gcall.Stepto(-42587, -35513, -1886);
		gcall.Stepto(-42339, -35495, -1832);
		gcall.Stepto(-42096, -35547, -1763);
		gcall.Stepto(-41871, -35652, -1711);
		gcall.Stepto(-41651, -35761, -1686);
		gcall.Stepto(-41422, -35865, -1643);
		gcall.Stepto(-41185, -35938, -1601);
		gcall.Stepto(-40946, -36005, -1560);
		gcall.Stepto(-40708, -36073, -1531);
		gcall.Stepto(-40469, -36141, -1521);
		gcall.Stepto(-40231, -36209, -1529);
		gcall.Stepto(-39993, -36277, -1513);
		gcall.Stepto(-39750, -36330, -1480);
		gcall.Stepto(-39505, -36363, -1459);
		gcall.Stepto(-39258, -36390, -1447);
		gcall.Stepto(-39010, -36415, -1429);
		gcall.Stepto(-38764, -36439, -1374);
		gcall.Stepto(-38515, -36463, -1229);
		gcall.Stepto(-38270, -36487, -1162);
		gcall.Stepto(-38021, -36511, -1113);
		gcall.Stepto(-37777, -36521, -974);
		gcall.Stepto(-37558, -36405, -935);
		gcall.Stepto(-37344, -36279, -884);
		gcall.Stepto(-37127, -36152, -817);
		gcall.Stepto(-36914, -36030, -750);
		gcall.Stepto(-36679, -36063, -653);
		gcall.Stepto(-36502, -36234, -553);
		gcall.Stepto(-36339, -36424, -462);
		gcall.Stepto(-36218, -36635, -426);
		gcall.Stepto(-36135, -36872, -403);
		gcall.Stepto(-36097, -37110, -391);
		gcall.Stepto(-36217, -37330, -381);
		gcall.Stepto(-36347, -37541, -379);
		gcall.Stepto(-36492, -37742, -376);
		gcall.Stepto(-36672, -37912, -372);
		gcall.Stepto(-36862, -38072, -378);
		gcall.Stepto(-36868, -38077, -378);
		gcall.NewSpend(1);
		Sleep(1000);
		gcall.DeliverQuests(306,taskid, L"역기산");
		Sleep(1000);
		gcall.Stepto(-36802, -38187, -379);
		gcall.Stepto(-36544, -38475, -379);
		gcall.Stepto(-36561, -38668, -378);
		gcall.DeliverQuests(0x150, 1, L"소붕");
		Sleep(1000);
		break;
	case 2:
		gcall.NewSpend(2.5);
		gcall.Stepto(-36656, -38045, -365);
		gcall.Stepto(-36411, -38007, -363);
		gcall.Stepto(-36166, -37971, -374);
		gcall.Stepto(-35928, -38029, -374);
		gcall.Stepto(-35717, -38159, -374);
		gcall.Stepto(-35520, -38311, -374);
		gcall.Stepto(-35333, -38474, -374);
		gcall.Stepto(-35303, -38500, -374);
		gcall.NewSpend(1);
		Sleep(1000);
		gcall.DeliverQuests(306,taskid,L"음소지");
		Sleep(1000);
		break;
	case 3:
		
		gcall.NewSpend(2.5);
		gcall.Stepto(-35353, -38308, -374, 10, 20);
		gcall.Stepto(-35416, -38201, -374, 10, 20);
		gcall.Stepto(-35480, -38094, -374, 10, 20);
		gcall.Stepto(-35544, -37987, -374, 10, 20);
		gcall.Stepto(-35607, -37881, -374, 10, 20);
		gcall.Stepto(-35671, -37775, -374, 10, 20);
		gcall.Stepto(-35735, -37668, -371, 10, 20);
		gcall.Stepto(-35799, -37562, -366, 10, 20);
		gcall.Stepto(-35862, -37455, -378, 10, 20);
		gcall.Stepto(-35926, -37349, -379, 10, 20);
		gcall.Stepto(-35990, -37243, -385, 10, 20);
		gcall.Stepto(-36054, -37136, -388, 10, 20);
		gcall.Stepto(-36119, -37027, -395, 10, 20);
		gcall.Stepto(-36180, -36919, -404, 10, 20);
		gcall.Stepto(-36220, -36802, -412, 10, 20);
		gcall.Stepto(-36249, -36682, -425, 10, 20);
		gcall.Stepto(-36278, -36561, -438, 10, 20);
		gcall.Stepto(-36307, -36440, -455, 10, 20);
		gcall.Stepto(-36336, -36320, -490, 10, 20);
		gcall.Stepto(-36370, -36201, -539, 10, 20);
		gcall.Stepto(-36433, -36095, -584, 10, 20);
		gcall.Stepto(-36535, -36024, -624, 10, 20);
		gcall.Stepto(-36656, -36001, -665, 10, 20);
		gcall.Stepto(-37016, -36081, -778, 10, 20);
		gcall.Stepto(-37241, -36193, -851, 10, 20);
		gcall.Stepto(-37428, -36355, -909, 10, 20);
		gcall.Stepto(-37520, -36438, -932, 10, 20);
		gcall.Stepto(-37612, -36522, -955, 10, 20);
		gcall.Stepto(-37704, -36605, -980, 10, 20);
		gcall.Stepto(-37796, -36688, -1008, 10, 20);
		gcall.Stepto(-37892, -36768, -1027, 10, 20);
		gcall.Stepto(-38007, -36810, -1044, 10, 20);
		gcall.Stepto(-38104, -36743, -1079, 10, 20);
		gcall.Stepto(-38150, -36628, -1126, 10, 20);
		gcall.Stepto(-38177, -36507, -1160, 10, 20);
		gcall.Stepto(-38180, -36383, -1186, 10, 20);
		gcall.Stepto(-38168, -36260, -1211, 10, 20);
		gcall.Stepto(-38156, -36136, -1241, 10, 20);
		gcall.Stepto(-38143, -36013, -1277, 10, 20);
		gcall.Stepto(-38131, -35890, -1315, 10, 20);
		gcall.Stepto(-38132, -35766, -1366, 10, 20);
		gcall.Stepto(-38188, -35525, -1450, 10, 20);
		gcall.Stepto(-38317, -35313, -1505, 10, 20);
		gcall.Stepto(-38450, -35104, -1538, 10, 20);
		gcall.Stepto(-38582, -34894, -1532, 10, 20);
		gcall.Stepto(-38713, -34684, -1524, 10, 20);
		gcall.Stepto(-38780, -34578, -1523, 10, 20, 10000);
		gcall.Stepto(-38918, -34369, -1532, 10, 20, 10000);
		gcall.Stepto(-39063, -34156, -1548, 10, 20, 10000);
		gcall.Stepto(-39192, -33967, -1565, 10, 20, 10000);
		gcall.NewSpend(1);
		gcall.FindThenKill(0, 1000, modeNormal | modeAoe | modePickup | modePickupBody);
		gcall.Stepto(-38753, -34051, -1519);
		gcall.Stepto(-38629, -34041, -1507);
		gcall.Stepto(-38506, -34026, -1497);
		gcall.Stepto(-38385, -34003, -1489);
		gcall.Stepto(-38263, -33978, -1486);
		gcall.Stepto(-38142, -33953, -1487);
		gcall.Stepto(-38020, -33928, -1490);
		gcall.Stepto(-37898, -33902, -1489);
		gcall.Stepto(-37776, -33877, -1486);
		gcall.Stepto(-37655, -33852, -1480);
		gcall.Stepto(-37533, -33826, -1473);
		gcall.Stepto(-37416, -33785, -1465);
		gcall.Stepto(-37228, -33628, -1452);
		gcall.Stepto(-37169, -33519, -1451);
		gcall.Stepto(-37085, -33286, -1452);
		gcall.Stepto(-37044, -33169, -1439);
		gcall.Stepto(-36962, -32935, -1395);
		gcall.Stepto(-36871, -32704, -1378);
		gcall.Stepto(-36746, -32491, -1325);
		gcall.Stepto(-36580, -32323, -1280);

		Sleep(1000);
		//丢火炉
		//MessageBox(0, 0, 0, MB_OK);
		gcall.Pickdown();
		Sleep(1000);
		gcall.randXianlu(0);
		Sleep(1000);

		gcall.Stepto(-36570, -32328, -1280);
		gcall.Stepto(-36744, -32507, -1331);
		gcall.Stepto(-36916, -32686, -1379);
		gcall.Stepto(-37081, -32871, -1417);
		gcall.Stepto(-37165, -32962, -1461);
		gcall.Stepto(-37334, -33144, -1500);
		gcall.Stepto(-37511, -33320, -1501);
		gcall.Stepto(-37605, -33401, -1508);
		gcall.Stepto(-37798, -33556, -1516);
		gcall.Stepto(-37896, -33632, -1515);
		gcall.Stepto(-38101, -33771, -1508);
		gcall.Stepto(-38228, -33794, -1504);
		gcall.Stepto(-38474, -33825, -1508);
		gcall.Stepto(-38715, -33881, -1521);
		break;
	case 4:
		gcall.NewSpend(2.5);
		gcall.Stepto(-38632, -34032, -1508,10,20,3000);
		gcall.Stepto(-38514, -34251, -1490);
		gcall.Stepto(-38397, -34469, -1478);
		gcall.Stepto(-38281, -34689, -1468);
		gcall.Stepto(-38189, -34918, -1478);
		gcall.Stepto(-38176, -35167, -1501);
		gcall.Stepto(-38172, -35415, -1465);
		gcall.Stepto(-38168, -35664, -1405);
		gcall.Stepto(-38164, -35912, -1310);
		gcall.Stepto(-38160, -36160, -1234);
		gcall.Stepto(-38156, -36408, -1178);
		gcall.Stepto(-38126, -36655, -1111);
		gcall.Stepto(-38076, -36768, -1067);
		gcall.Stepto(-37856, -36780, -1022);
		gcall.Stepto(-37682, -36603, -977);
		gcall.Stepto(-37501, -36434, -928);
		gcall.Stepto(-37317, -36268, -877);
		gcall.Stepto(-37128, -36107, -814);
		gcall.Stepto(-37024, -36040, -786);
		gcall.Stepto(-36784, -36004, -701);
		gcall.Stepto(-36665, -36039, -660);
		gcall.Stepto(-36463, -36178, -572);
		gcall.Stepto(-36344, -36398, -469);
		gcall.Stepto(-36253, -36629, -430);
		gcall.Stepto(-36163, -36860, -404);
		gcall.Stepto(-36074, -37091, -391);
		gcall.Stepto(-35984, -37323, -379);
		gcall.Stepto(-35876, -37545, -366);
		gcall.Stepto(-35742, -37754, -369);
		gcall.Stepto(-35604, -37960, -374);
		gcall.Stepto(-35471, -38169, -374);
		gcall.Stepto(-35337, -38379, -374);
		gcall.Stepto(-35279, -38471, -374);
		gcall.NewSpend(1);
		Sleep(1000);
		gcall.DeliverQuests(306,taskid, L"음소지");
		Sleep(1000);
		break;
	case 5:
		gcall.NewSpend(2.5);
		gcall.Stepto(-35437, -38439, -374);
		gcall.Stepto(-35656, -38323, -374);
		gcall.Stepto(-35875, -38206, -374);
		gcall.Stepto(-36095, -38089, -374);
		gcall.Stepto(-36329, -38016, -374);
		gcall.Stepto(-36564, -38044, -358);
		gcall.Stepto(-36814, -38106, -379);
		gcall.Stepto(-36853, -38116, -379);
		gcall.NewSpend(1);
		Sleep(1000);
		gcall.DeliverQuests(306,taskid, L"역기산");
		Sleep(1500);
		
		break;
	}

}

void TaskScript::Task_307(int taskid)
{
	switch (taskid)
	{
	case 1:
		gcall.Stepto(-36844, -38003, -377);
		Sleep(500);
		gcall.NPCJieRenWu(0xB9, 0x4006B, 0x15A, 0, 0);
		Sleep(1000);
		gcall.NewSpend(2.5);
		gcall.Stepto(-36497, -37940, -357);
		gcall.Stepto(-36142, -37939, -374);
		gcall.Stepto(-35819, -38065, -374);
		gcall.Stepto(-35561, -38264, -374);
		gcall.Stepto(-35308, -38470, -374);
		Sleep(1000);
		gcall.DeliverQuests(346, 1, L"음소지");
		Sleep(1000);
		gcall.NewSpend(2.5);
		gcall.Stepto(-3460, -6188, 627);
		gcall.Stepto(-3543, -6151, 626);
		gcall.Stepto(-3766, -6051, 605);
		gcall.Stepto(-4003, -6033, 576);
		gcall.Stepto(-4238, -6127, 556);
		gcall.Stepto(-4309, -6156, 560);
		gcall.Stepto(-4466, -5729, 559);
		gcall.Stepto(-4682, -5613, 557);
		gcall.Stepto(-4907, -5492, 551);
		gcall.Stepto(-5122, -5377, 550);
		gcall.Stepto(-5338, -5260, 554);
		gcall.Stepto(-5565, -5149, 559);
		gcall.Stepto(-5786, -5045, 563);
		gcall.Stepto(-6014, -4937, 566);
		gcall.Stepto(-6235, -4833, 559);
		gcall.Stepto(-6459, -4718, 541);
		gcall.Stepto(-6652, -4614, 551);
		gcall.Stepto(-6891, -4486, 560);
		gcall.Stepto(-7112, -4367, 584);
		gcall.Stepto(-7327, -4251, 598);
		gcall.Stepto(-7551, -4138, 599);
		gcall.Stepto(-7781, -4033, 601);
		gcall.Stepto(-8014, -3944, 601);
		gcall.Stepto(-8247, -3882, 595);
		gcall.Stepto(-8493, -3815, 570);
		gcall.Stepto(-8731, -3751, 583);
		gcall.Stepto(-8968, -3760, 602);
		gcall.Stepto(-9160, -3918, 602);
		gcall.Stepto(-9351, -4082, 602);
		gcall.Stepto(-9539, -4246, 602);
		gcall.Stepto(-9724, -4413, 602);
		gcall.Stepto(-9907, -4578, 602);
		gcall.Stepto(-10095, -4747, 602);
		gcall.Stepto(-10275, -4910, 602);
		gcall.Stepto(-10462, -5078, 602);
		gcall.Stepto(-10646, -5244, 602);
		gcall.Stepto(-10845, -5394, 603);
		gcall.Stepto(-11050, -5529, 621);
		gcall.Stepto(-11278, -5616, 641);
		gcall.Stepto(-11529, -5621, 657);
		gcall.Stepto(-11766, -5564, 656);
		gcall.Stepto(-12012, -5493, 665);
		gcall.Stepto(-12247, -5426, 646);
		gcall.Stepto(-12491, -5382, 635);
		gcall.Stepto(-12737, -5433, 605);
		gcall.Stepto(-12964, -5525, 596);
		gcall.Stepto(-13195, -5628, 579);
		gcall.Stepto(-13398, -5763, 590);
		gcall.Stepto(-13589, -5929, 562);
		gcall.Stepto(-13775, -6089, 532);
		gcall.Stepto(-13959, -6242, 455);
		gcall.Stepto(-14179, -6392, 354);
		gcall.Stepto(-14401, -6493, 231);
		gcall.Stepto(-14450, -6515, 206);
		gcall.Stepto(-14556, -6561, 157);
		gcall.Stepto(-14805, -6596, 20);
		gcall.Stepto(-15050, -6604, -39);
		gcall.Stepto(-15303, -6612, -66);
		gcall.Stepto(-15548, -6619, -83);
		gcall.Stepto(-15801, -6628, -112);
		gcall.Stepto(-16046, -6637, -141);
		gcall.Stepto(-16291, -6703, -170);
		gcall.Stepto(-16506, -6819, -183);
		gcall.Stepto(-16710, -6967, -187);
		gcall.Stepto(-16896, -7127, -190);
		gcall.Stepto(-17061, -7317, -191);
		gcall.Stepto(-17125, -7552, -186);
		gcall.Stepto(-17119, -7805, -207);
		gcall.Stepto(-17055, -8042, -235);
		gcall.Stepto(-16950, -8263, -255);
		gcall.Stepto(-16817, -8476, -283);
		gcall.Stepto(-16649, -8654, -330);
		gcall.Stepto(-16475, -8838, -374);
		gcall.Stepto(-16304, -9020, -413);
		gcall.Stepto(-16140, -9202, -452);
		gcall.Stepto(-15971, -9387, -491);
		gcall.Stepto(-15791, -9553, -520);
		gcall.Stepto(-15605, -9724, -538);
		gcall.Stepto(-15424, -9889, -567);
		gcall.Stepto(-15238, -10060, -605);
		gcall.Stepto(-15057, -10225, -639);
		gcall.Stepto(-14871, -10396, -677);
		gcall.Stepto(-14684, -10567, -719);
		gcall.Stepto(-14499, -10726, -748);
		gcall.Stepto(-14310, -10881, -774);
		gcall.Stepto(-14107, -11038, -807);
		gcall.Stepto(-13905, -11189, -848);
		gcall.Stepto(-13707, -11332, -889);
		gcall.Stepto(-13481, -11447, -919);
		gcall.Stepto(-13258, -11546, -942);
		gcall.Stepto(-13027, -11649, -993);
		gcall.Stepto(-12803, -11748, -1051);
		gcall.Stepto(-12572, -11851, -1098);
		gcall.Stepto(-12348, -11950, -1115);
		gcall.Stepto(-12271, -11984, -1127);
		gcall.Stepto(-12243, -11997, -1130);
		gcall.Stepto(-12012, -12099, -1168);
		gcall.Stepto(-11786, -12200, -1212);
		gcall.Stepto(-11562, -12299, -1265);
		gcall.Stepto(-11328, -12403, -1334);
		gcall.Stepto(-11104, -12502, -1384);
		gcall.Stepto(-10878, -12603, -1409);
		gcall.Stepto(-10651, -12704, -1454);
		gcall.Stepto(-10420, -12806, -1498);
		gcall.Stepto(-10194, -12907, -1540);
		gcall.Stepto(-9964, -13009, -1589);
		gcall.Stepto(-9742, -13110, -1617);
		gcall.Stepto(-9524, -13238, -1639);
		gcall.Stepto(-9325, -13381, -1650);
		gcall.Stepto(-9155, -13562, -1665);
		gcall.Stepto(-8997, -13759, -1679);
		gcall.Stepto(-8855, -13968, -1699);
		gcall.Stepto(-8748, -14186, -1714);
		gcall.Stepto(-8660, -14426, -1718);
		gcall.Stepto(-8586, -14660, -1722);
		gcall.Stepto(-8515, -14901, -1730);
		gcall.Stepto(-8446, -15137, -1743);
		gcall.Stepto(-8376, -15378, -1762);
		gcall.Stepto(-8305, -15621, -1782);
		gcall.Stepto(-8254, -15860, -1792);
		gcall.Stepto(-8228, -16109, -1791);
		gcall.Stepto(-8208, -16354, -1784);
		gcall.Stepto(-8189, -16592, -1775);
		gcall.Stepto(-8167, -16854, -1759);
		gcall.Stepto(-8147, -17104, -1744);
		gcall.Stepto(-8127, -17348, -1732);
		gcall.Stepto(-8076, -17593, -1723);
		gcall.Stepto(-7977, -17826, -1716);
		gcall.Stepto(-7856, -18036, -1713);
		gcall.Stepto(-7698, -18234, -1719);
		gcall.Stepto(-7499, -18386, -1730);
		gcall.Stepto(-7278, -18472, -1730);
		gcall.Stepto(-7031, -18555, -1749);
		gcall.Stepto(-6800, -18633, -1770);
		gcall.Stepto(-6563, -18723, -1802);
		gcall.Stepto(-6352, -18850, -1846);
		gcall.Stepto(-6155, -19008, -1867);
		gcall.Stepto(-6010, -19203, -1870);
		gcall.Stepto(-5903, -19431, -1897);
		gcall.Stepto(-5823, -19671, -1902);
		gcall.Stepto(-5746, -19903, -1895);
		gcall.Stepto(-5696, -20151, -1889);
		gcall.Stepto(-5663, -20393, -1886);
		gcall.Stepto(-5661, -20646, -1870);
		gcall.Stepto(-5696, -20888, -1868);
		gcall.Stepto(-5768, -21130, -1869);
		gcall.Stepto(-5849, -21365, -1873);
		gcall.Stepto(-5930, -21597, -1874);
		gcall.Stepto(-6012, -21836, -1876);
		gcall.Stepto(-6095, -22075, -1889);
		gcall.Stepto(-6161, -22310, -1906);
		gcall.Stepto(-6126, -22559, -1926);
		gcall.Stepto(-6019, -22778, -1937);
		gcall.Stepto(-5896, -22999, -1961);
		gcall.Stepto(-5772, -23220, -1972);
		gcall.Stepto(-5653, -23434, -1997);
		gcall.Stepto(-5533, -23656, -2016);
		gcall.Stepto(-5429, -23877, -2059);
		gcall.Stepto(-5390, -24109, -2114);
		gcall.Stepto(-5390, -24110, -2114);
		gcall.Stepto(-5370, -24253, -2149);
		gcall.Stepto(-5359, -24502, -2204);
		gcall.Stepto(-5354, -24628, -2227);
		gcall.Stepto(-5341, -24840, -2282);
		gcall.Stepto(-5276, -25084, -2331);
		gcall.Stepto(-5198, -25310, -2374);
		gcall.Stepto(-5103, -25549, -2421);
		gcall.Stepto(-5010, -25776, -2452);
		gcall.Stepto(-4913, -26010, -2467);
		gcall.Stepto(-4803, -26238, -2467);
		gcall.Stepto(-4695, -26459, -2458);
		gcall.Stepto(-4587, -26679, -2451);
		gcall.Stepto(-4473, -26904, -2459);
		gcall.Stepto(-4349, -27120, -2471);
		gcall.Stepto(-4212, -27332, -2483);
		gcall.Stepto(-4070, -27531, -2499);
		gcall.Stepto(-3918, -27734, -2510);
		gcall.Stepto(-3758, -27930, -2515);
		gcall.Stepto(-3604, -28119, -2535);
		gcall.Stepto(-3541, -28197, -2539);
		gcall.Stepto(-3399, -28371, -2545);
		gcall.Stepto(-3244, -28561, -2554);
		gcall.Stepto(-3085, -28757, -2580);
		gcall.Stepto(-2930, -28947, -2612);
		gcall.Stepto(-2771, -29143, -2628);
		gcall.Stepto(-2611, -29340, -2651);
		gcall.Stepto(-2457, -29530, -2662);
		gcall.Stepto(-2299, -29723, -2684);
		gcall.Stepto(-2140, -29919, -2710);
		gcall.Stepto(-1986, -30108, -2732);
		gcall.Stepto(-1970, -30128, -2734);
		gcall.Stepto(-1913, -30198, -2741);
		gcall.Stepto(-1753, -30394, -2761);
		gcall.Stepto(-1598, -30584, -2771);
		gcall.Stepto(-1439, -30780, -2772);
		gcall.Stepto(-1280, -30975, -2800);
		gcall.Stepto(-1127, -31164, -2814);
		gcall.Stepto(-968, -31359, -2818);
		gcall.Stepto(-808, -31555, -2827);
		gcall.Stepto(-654, -31745, -2844);
		gcall.Stepto(-494, -31941, -2866);
		gcall.Stepto(-339, -32133, -2874);
		gcall.Stepto(-206, -32342, -2882);
		gcall.Stepto(-203, -32596, -2882);
		gcall.Stepto(-280, -32832, -2886);
		gcall.Stepto(-419, -33033, -2876);
		gcall.Stepto(-598, -33212, -2849);
		gcall.Stepto(-818, -33317, -2827);
		gcall.Stepto(-1055, -33404, -2810);
		gcall.Stepto(-1289, -33491, -2807);
		gcall.Stepto(-1526, -33578, -2807);
		gcall.Stepto(-1756, -33663, -2807);
		gcall.Stepto(-1993, -33750, -2812);
		gcall.Stepto(-2231, -33838, -2822);
		gcall.Stepto(-2460, -33922, -2839);
		gcall.Stepto(-2707, -33979, -2859);
		gcall.Stepto(-2944, -33951, -2874);
		gcall.Stepto(-3163, -33824, -2886);
		gcall.Stepto(-3374, -33685, -2902);
		gcall.Stepto(-3578, -33551, -2907);
		gcall.Stepto(-3790, -33411, -2927);
		gcall.Stepto(-4002, -33272, -2923);
		gcall.Stepto(-4206, -33138, -2914);
		gcall.Stepto(-4405, -32982, -2912);
		gcall.Stepto(-4597, -32831, -2906);
		gcall.Stepto(-4800, -32683, -2906);
		gcall.Stepto(-5005, -32535, -2905);
		gcall.Stepto(-5209, -32384, -2901);
		gcall.Stepto(-5398, -32230, -2907);
		gcall.Stepto(-5594, -32070, -2905);
		gcall.Stepto(-5792, -31908, -2911);
		gcall.Stepto(-5988, -31748, -2885);
		gcall.Stepto(-6184, -31588, -2845);
		gcall.Stepto(-6367, -31439, -2840);
		gcall.Stepto(-6569, -31273, -2836);
		gcall.Stepto(-6765, -31113, -2812);
		gcall.Stepto(-6955, -30958, -2766);
		gcall.Stepto(-7151, -30798, -2723);
		gcall.Stepto(-7347, -30638, -2706);
		gcall.Stepto(-7538, -30481, -2696);
		gcall.Stepto(-7734, -30321, -2696);
		gcall.Stepto(-7932, -30159, -2704);
		gcall.Stepto(-8133, -29996, -2691);
		gcall.Stepto(-8328, -29836, -2674);
		gcall.Stepto(-8518, -29681, -2616);
		gcall.Stepto(-8723, -29535, -2539);
		gcall.Stepto(-8962, -29453, -2453);
		gcall.Stepto(-9212, -29399, -2354);
		gcall.Stepto(-9453, -29357, -2281);
		gcall.Stepto(-9703, -29320, -2197);
		gcall.Stepto(-9953, -29282, -2111);
		gcall.Stepto(-10195, -29246, -2031);
		gcall.Stepto(-10445, -29209, -1963);
		gcall.Stepto(-10695, -29169, -1895);
		gcall.Stepto(-10795, -29148, -1874);
		gcall.Stepto(-11044, -29097, -1829);
		gcall.Stepto(-11292, -29046, -1773);
		gcall.Stepto(-11531, -28980, -1730);
		gcall.Stepto(-11733, -28833, -1694);
		gcall.Stepto(-11888, -28644, -1670);
		gcall.Stepto(-12047, -28447, -1654);
		gcall.Stepto(-12206, -28250, -1634);
		gcall.Stepto(-12369, -28057, -1611);
		gcall.Stepto(-12561, -27907, -1585);
		gcall.Stepto(-12803, -27843, -1546);
		gcall.Stepto(-13053, -27873, -1512);
		gcall.Stepto(-13297, -27924, -1481);
		gcall.Stepto(-13541, -27976, -1450);
		gcall.Stepto(-13779, -28045, -1413);
		gcall.Stepto(-14017, -28139, -1377);
		gcall.Stepto(-14242, -28235, -1374);
		gcall.Stepto(-14471, -28342, -1345);
		gcall.Stepto(-14697, -28456, -1332);
		gcall.Stepto(-14916, -28567, -1338);
		gcall.Stepto(-15136, -28694, -1302);
		gcall.Stepto(-15280, -28891, -1280);
		gcall.Stepto(-15404, -29121, -1259);
		gcall.Stepto(-15531, -29328, -1233);
		gcall.Stepto(-15716, -29501, -1203);
		gcall.Stepto(-15929, -29639, -1192);
		gcall.Stepto(-16076, -29711, -1180);
		gcall.Stepto(-16256, -29800, -1175);
		gcall.Stepto(-16484, -29911, -1177);
		gcall.Stepto(-16703, -30019, -1177);
		gcall.Stepto(-16930, -30130, -1178);
		gcall.Stepto(-17159, -30242, -1182);
		gcall.Stepto(-17381, -30351, -1181);
		gcall.Stepto(-17608, -30463, -1172);
		gcall.Stepto(-17835, -30574, -1165);
		gcall.Stepto(-18065, -30687, -1155);
		gcall.Stepto(-18292, -30798, -1141);
		gcall.Stepto(-18511, -30906, -1115);
		gcall.Stepto(-18737, -31020, -1087);
		gcall.Stepto(-18976, -31116, -1061);
		gcall.Stepto(-19213, -31196, -1079);
		gcall.Stepto(-19454, -31273, -1126);
		gcall.Stepto(-19688, -31345, -1168);
		gcall.Stepto(-19916, -31402, -1163);
		gcall.Stepto(-20181, -31432, -1147);
		gcall.Stepto(-20434, -31435, -1126);
		gcall.Stepto(-20689, -31417, -1140);
		gcall.Stepto(-20941, -31393, -1162);
		gcall.Stepto(-21182, -31351, -1161);
		gcall.Stepto(-21428, -31293, -1138);
		gcall.Stepto(-21671, -31222, -1128);
		gcall.Stepto(-21913, -31147, -1154);
		gcall.Stepto(-22147, -31071, -1192);
		gcall.Stepto(-22388, -30994, -1188);
		gcall.Stepto(-22629, -30916, -1174);
		gcall.Stepto(-22863, -30841, -1186);
		gcall.Stepto(-23104, -30764, -1175);
		gcall.Stepto(-23344, -30686, -1125);
		gcall.Stepto(-23586, -30610, -1075);
		gcall.Stepto(-23828, -30535, -1050);
		gcall.Stepto(-24062, -30463, -1046);
		gcall.Stepto(-24303, -30389, -1046);
		gcall.Stepto(-24545, -30314, -1044);
		gcall.Stepto(-24786, -30240, -1056);
		gcall.Stepto(-25028, -30166, -1056);
		gcall.Stepto(-25272, -30098, -1048);
		gcall.Stepto(-25513, -30036, -1032);
		gcall.Stepto(-25760, -29986, -1034);
		gcall.Stepto(-26015, -29965, -1050);
		gcall.Stepto(-26261, -29951, -1065);
		gcall.Stepto(-26514, -29951, -1078);
		gcall.Stepto(-26758, -29951, -1074);
		gcall.Stepto(-27006, -29997, -1070);
		gcall.Stepto(-27243, -30086, -1075);
		gcall.Stepto(-27485, -30158, -1080);
		gcall.Stepto(-27733, -30207, -1078);
		gcall.Stepto(-27983, -30247, -1076);
		gcall.Stepto(-28227, -30269, -1074);
		gcall.Stepto(-28479, -30290, -1076);
		gcall.Stepto(-28727, -30311, -1080);
		gcall.Stepto(-28979, -30353, -1074);
		gcall.Stepto(-29230, -30402, -1070);
		gcall.Stepto(-29477, -30449, -1081);
		gcall.Stepto(-29721, -30515, -1098);
		gcall.Stepto(-29953, -30613, -1105);
		gcall.Stepto(-30111, -30806, -1088);
		gcall.Stepto(-30187, -31050, -1045);
		gcall.Stepto(-30253, -31288, -964);
		gcall.Stepto(-30313, -31533, -897);
		gcall.Stepto(-30354, -31784, -828);
		gcall.Stepto(-30394, -32033, -756);
		gcall.Stepto(-30450, -32271, -714);
		gcall.Stepto(-30543, -32506, -691);
		gcall.Stepto(-30662, -32729, -703);
		gcall.Stepto(-30775, -32955, -704);
		gcall.Stepto(-30885, -33179, -724);
		gcall.Stepto(-30998, -33405, -720);
		gcall.Stepto(-31120, -33626, -762);
		gcall.Stepto(-31261, -33837, -819);
		gcall.Stepto(-31406, -34024, -871);
		gcall.Stepto(-31594, -34210, -902);
		gcall.Stepto(-31788, -34360, -935);
		gcall.Stepto(-32002, -34504, -954);
		gcall.Stepto(-32214, -34626, -973);
		gcall.Stepto(-32431, -34748, -1000);
		gcall.Stepto(-32651, -34872, -1027);
		gcall.Stepto(-32868, -34993, -1056);
		gcall.Stepto(-33091, -35117, -1090);
		gcall.Stepto(-33318, -35226, -1130);
		gcall.Stepto(-33558, -35304, -1154);
		gcall.Stepto(-33805, -35364, -1148);
		gcall.Stepto(-34039, -35396, -1122);
		gcall.Stepto(-34300, -35411, -1085);
		gcall.Stepto(-34556, -35422, -1052);
		gcall.Stepto(-34809, -35433, -1032);
		gcall.Stepto(-35053, -35445, -1000);
		gcall.Stepto(-35308, -35475, -949);
		gcall.Stepto(-35486, -35628, -899);
		gcall.Stepto(-35426, -35862, -797);
		gcall.Stepto(-35280, -36073, -688);
		gcall.Stepto(-35137, -36282, -604);
		gcall.Stepto(-35044, -36513, -514);
		gcall.Stepto(-35062, -36759, -451);
		gcall.Stepto(-35181, -36981, -394);
		gcall.Stepto(-35355, -37162, -379);
		gcall.Stepto(-35547, -37324, -379);
		gcall.Stepto(-35746, -37469, -376);
		gcall.Stepto(-35952, -37602, -366);
		gcall.Stepto(-36182, -37732, -375);
		gcall.Stepto(-36405, -37848, -372);
		gcall.Stepto(-36627, -37964, -363);
		gcall.Stepto(-36834, -38073, -378);
		gcall.Stepto(-36836, -38074, -378);
		gcall.Stepto(-36853, -38116, -379);
		gcall.Stepto(-36865, -38093, -378);
		gcall.Stepto(-36773, -38058, -378);
		gcall.Stepto(-36534, -38005, -356);
		gcall.Stepto(-36291, -37959, -374);
		gcall.Stepto(-36040, -37928, -374);
		gcall.Stepto(-35797, -37898, -374);
		gcall.Stepto(-35544, -37894, -374);
		gcall.Stepto(-35300, -37896, -374);
		gcall.Stepto(-35140, -37905, -375);
		gcall.Stepto(-35140, -37905, -375);
		gcall.Stepto(-35144, -37689, -378);
		gcall.Stepto(-35143, -37436, -379);
		gcall.Stepto(-35056, -37211, -393);
		gcall.Stepto(-34861, -37052, -417);
		gcall.Stepto(-34672, -36959, -433);
		gcall.Stepto(-34629, -36939, -436);
		gcall.Stepto(-34460, -36861, -441);
		gcall.Stepto(-34454, -36858, -441);
		gcall.Stepto(-34233, -36756, -514);
		gcall.Stepto(-34005, -36645, -823);
		gcall.Stepto(-33797, -36516, -1138);
		gcall.Stepto(-33620, -36349, -1177);
		gcall.Stepto(-33430, -36181, -1167);
		gcall.Stepto(-33244, -36036, -1110);
		gcall.Stepto(-33060, -35852, -1045);
		gcall.Stepto(-32887, -35663, -1010);
		gcall.Stepto(-32722, -35483, -988);
		gcall.Stepto(-32551, -35296, -975);
		gcall.Stepto(-32386, -35115, -961);
		gcall.Stepto(-32220, -34934, -954);
		gcall.Stepto(-32051, -34750, -950);
		gcall.Stepto(-31881, -34563, -943);
		gcall.Stepto(-31714, -34381, -923);
		gcall.Stepto(-31547, -34199, -896);
		gcall.Stepto(-31390, -33997, -865);
		gcall.Stepto(-31246, -33800, -810);
		gcall.Stepto(-31107, -33599, -756);
		gcall.Stepto(-30972, -33389, -720);
		gcall.Stepto(-30929, -33307, -724);
		gcall.Stepto(-30895, -33242, -727);
		gcall.Stepto(-30789, -33016, -705);
		gcall.Stepto(-30690, -32792, -705);
		gcall.Stepto(-30606, -32553, -698);
		gcall.Stepto(-30517, -32326, -705);
		gcall.Stepto(-30425, -32090, -744);
		gcall.Stepto(-30369, -31848, -810);
		gcall.Stepto(-30335, -31606, -877);
		gcall.Stepto(-30335, -31376, -939);
		gcall.Stepto(-30335, -31362, -942);
		gcall.Stepto(-30355, -31110, -1007);
		gcall.Stepto(-30383, -30867, -1065);
		gcall.Stepto(-30412, -30615, -1122);
		gcall.Stepto(-30440, -30372, -1158);
		gcall.Stepto(-30469, -30121, -1181);
		gcall.Stepto(-30497, -29878, -1194);
		gcall.Stepto(-30524, -29638, -1194);
		gcall.Stepto(-30553, -29383, -1186);
		gcall.Stepto(-30582, -29135, -1180);
		gcall.Stepto(-30610, -28890, -1176);
		gcall.Stepto(-30638, -28644, -1174);
		gcall.Stepto(-30667, -28396, -1172);
		gcall.Stepto(-30695, -28144, -1172);
		gcall.Stepto(-30720, -27900, -1175);
		gcall.Stepto(-30744, -27648, -1177);
		gcall.Stepto(-30767, -27405, -1177);
		gcall.Stepto(-30791, -27157, -1171);
		gcall.Stepto(-30823, -26907, -1157);
		gcall.Stepto(-30902, -26678, -1111);
		gcall.Stepto(-30985, -26439, -1118);
		gcall.Stepto(-31019, -26198, -1067);
		gcall.Stepto(-30882, -26007, -996);
		gcall.Stepto(-30664, -25897, -992);
		gcall.Stepto(-30521, -25823, -990);
		gcall.Stepto(-30533, -25690, -993);
		gcall.Stepto(-30538, -25625, -991);
		gcall.NewSpend(1);
		Sleep(1000);
		gcall.DeliverQuests(346, 2, L"육지평");
		Sleep(1000);
		gcall.DeliverQuests(307,taskid, L"기봉사");
		Sleep(1000);
		gcall.HeChengWuQi(EQUITMENT_POS::WUQI);
		Sleep(1000);
		gcall.SellItemByConfig(L"이화상");
		Sleep(1000);
		gcall.SortBag();
		Sleep(1000);
		break;
	case 2:
		gcall.NewSpend(2.5);
		gcall.Stepto(-30622, -25847, -991);
		gcall.Stepto(-30862, -25909, -994);
		gcall.Stepto(-31109, -25920, -1004);
		gcall.Stepto(-31353, -25886, -1051);
		gcall.Stepto(-31598, -25839, -1052);
		gcall.Stepto(-31834, -25763, -1052);
		gcall.Stepto(-32070, -25686, -1049);
		gcall.Stepto(-32306, -25610, -1049);
		gcall.Stepto(-32538, -25535, -1046);
		gcall.Stepto(-32779, -25457, -1056);
		gcall.Stepto(-33015, -25381, -1078);
		gcall.Stepto(-33251, -25304, -1103);
		gcall.Stepto(-33485, -25228, -1126);
		gcall.Stepto(-33715, -25137, -1140);
		gcall.Stepto(-33940, -25025, -1162);
		gcall.Stepto(-34159, -24916, -1186);
		gcall.Stepto(-34383, -24805, -1185);
		gcall.Stepto(-34622, -24758, -1191);
		gcall.Stepto(-34868, -24801, -1202);
		gcall.Stepto(-35103, -24876, -1207);
		gcall.Stepto(-35338, -24956, -1249);
		gcall.Stepto(-35572, -25038, -1278);
		gcall.Stepto(-35802, -25118, -1309);
		gcall.Stepto(-36040, -25201, -1344);
		gcall.Stepto(-36274, -25283, -1387);
		gcall.Stepto(-36511, -25352, -1424);
		gcall.Stepto(-36760, -25347, -1462);
		gcall.Stepto(-36994, -25269, -1478);
		gcall.Stepto(-37208, -25143, -1482);
		gcall.Stepto(-37418, -25011, -1500);
		gcall.Stepto(-37628, -24880, -1513);
		gcall.Stepto(-37839, -24748, -1522);
		gcall.Stepto(-38047, -24617, -1543);
		gcall.Stepto(-38258, -24485, -1553);
		gcall.Stepto(-38470, -24352, -1532);
		gcall.Stepto(-38680, -24220, -1482);
		gcall.Stepto(-38887, -24085, -1428);
		gcall.Stepto(-39040, -23891, -1394);
		gcall.Stepto(-39111, -23655, -1400);
		gcall.Stepto(-39118, -23410, -1365);
		gcall.Stepto(-39062, -23165, -1377);
		gcall.Stepto(-38976, -22932, -1331);
		gcall.NewSpend(1);
		Sleep(5000);
		gcall.Stepto(-38916, -22807, -1340);
		gcall.WaitPlans();
		gcall.NewSpend(2.5);
		gcall.Stepto(-38687, -22259, -1467);
		gcall.Stepto(-38636, -22019, -1460);
		gcall.Stepto(-38681, -21780, -1417);
		gcall.Stepto(-38827, -21580, -1361);
		gcall.Stepto(-39002, -21398, -1298);
		gcall.Stepto(-39176, -21222, -1210);
		gcall.Stepto(-39348, -21048, -1117);
		gcall.Stepto(-39551, -20899, -1014);
		gcall.Stepto(-39760, -20766, -959);
		gcall.Stepto(-39967, -20634, -932);
		gcall.Stepto(-40174, -20498, -932);
		gcall.Stepto(-40378, -20356, -935);
		gcall.Stepto(-40577, -20216, -934);
		gcall.Stepto(-40783, -20066, -932);
		gcall.NewSpend(1);
		gcall.Stepto(-40984, -19921, -929);
		gcall.Stepto(-41182, -19771, -929);
		gcall.Stepto(-41356, -19637, -934);
		gcall.Stepto(-41513, -19515, -931);
		gcall.Stepto(-41671, -19393, -928);
		gcall.Stepto(-41829, -19271, -930);
		gcall.Stepto(-41986, -19149, -935);
		gcall.Stepto(-42144, -19027, -929);
		gcall.Stepto(-42300, -18907, -936);
		gcall.Stepto(-42458, -18785, -936);
		gcall.Stepto(-42615, -18663, -937);
		gcall.Stepto(-42771, -18543, -931);
		gcall.Stepto(-42928, -18421, -936);
		gcall.Stepto(-43086, -18299, -936);
		gcall.Stepto(-43243, -18178, -936);
		gcall.Stepto(-43400, -18057, -933);
		gcall.Stepto(-43560, -17941, -934);
		gcall.Stepto(-43733, -17839, -935);
		gcall.FindThenKill(0, 900, modeNormal | modeAoe | modePickup);
		gcall.NewSpend(2.5);
		gcall.Stepto(-44228, -17506, -1033);
		gcall.Stepto(-44385, -17385, -1116);
		gcall.Stepto(-44539, -17260, -1198);
		gcall.Stepto(-44693, -17135, -1288);
		gcall.Stepto(-44844, -17012, -1365);
		gcall.Stepto(-45002, -16884, -1439);
		gcall.Stepto(-45164, -16770, -1447);
		gcall.Stepto(-45336, -16667, -1438);
		gcall.Stepto(-45510, -16573, -1461);
		gcall.Stepto(-45689, -16490, -1490);
		gcall.Stepto(-45873, -16416, -1519);
		gcall.Stepto(-46060, -16344, -1548);
		gcall.Stepto(-46246, -16274, -1576);
		gcall.Stepto(-46433, -16208, -1598);
		gcall.Stepto(-46629, -16189, -1603);
		gcall.Stepto(-46827, -16208, -1601);
		gcall.Stepto(-47024, -16228, -1603);
		gcall.Stepto(-47222, -16247, -1628);
		gcall.Stepto(-47419, -16264, -1626);
		gcall.Stepto(-47618, -16232, -1614);
		gcall.Stepto(-47810, -16183, -1615);
		gcall.Stepto(-48002, -16132, -1615);
		gcall.Stepto(-48195, -16081, -1611);
		gcall.Stepto(-48392, -16056, -1608);
		gcall.Stepto(-48590, -16061, -1612);
		gcall.Stepto(-48785, -16097, -1615);
		gcall.Stepto(-48972, -16162, -1610);
		gcall.NewSpend(1);
		gcall.FindThenKill(0, 900, modeNormal | modeAoe | modePickup | modeGoback);
		gcall.Stepto(-48713, -16085, -1615);
		gcall.Stepto(-48509, -15996, -1601);
		gcall.Stepto(-48364, -15929, -1604);
		gcall.Stepto(-48219, -15986, -1607);
		gcall.Stepto(-47987, -16076, -1615);
		gcall.Stepto(-47748, -16133, -1614);
		gcall.Stepto(-47581, -16310, -1617);
		gcall.Stepto(-47550, -16376, -1624);
		gcall.Stepto(-47367, -16489, -1625);
		gcall.Stepto(-47145, -16599, -1615);
		gcall.Stepto(-46911, -16680, -1607);
		gcall.Stepto(-46668, -16729, -1619);
		gcall.Stepto(-46424, -16768, -1619);
		gcall.Stepto(-46177, -16763, -1576);
		gcall.Stepto(-45931, -16730, -1497);
		gcall.Stepto(-45681, -16728, -1463);
		gcall.Stepto(-45435, -16734, -1443);
		gcall.Stepto(-45363, -16736, -1438);
		gcall.Stepto(-45345, -16607, -1439);
		gcall.Stepto(-45479, -16479, -1456);
		gcall.Stepto(-45659, -16308, -1502);
		gcall.Stepto(-45838, -16136, -1549);
		gcall.Stepto(-45986, -15994, -1580);
		gcall.Stepto(-46087, -15975, -1591);
		gcall.Stepto(-46330, -15927, -1599);
		gcall.Stepto(-46574, -15879, -1597);
		gcall.Stepto(-46666, -15901, -1597);
		gcall.Stepto(-46876, -16033, -1598);
		gcall.Stepto(-47087, -16164, -1610);
		gcall.Stepto(-47297, -16295, -1630);
		gcall.Stepto(-47352, -16330, -1631);
		gcall.FindThenKill(0, 900, modeNormal | modeAoe | modePickup | modeGoback);
		gcall.Stepto(-46691, -15764, -1608);
		Sleep(5000);
		gcall.FindThenKill(0, 300, modeNormal | modeAoe | modePickup);
		gcall.Stepto(-46691, -15764, -1608);
		Sleep(1000);
		gcall.PickupTask();
		Sleep(1000);
		gcall.Stepto(-46691, -15764, -1608);
		gcall.Stepto(-46535, -15908, -1597);
		gcall.Stepto(-46328, -16030, -1600);
		gcall.Stepto(-46082, -16067, -1581);
		gcall.Stepto(-45837, -16111, -1522);
		gcall.Stepto(-45671, -16154, -1482);
		Sleep(2000);
		gcall.FindThenKill(0, 300, modeNormal | modeAoe | modePickup);
		gcall.Stepto(-45837, -16111, -1522);
		gcall.Stepto(-45671, -16154, -1482);
		Sleep(1000);
		gcall.PickupTask();
		Sleep(1000);
		gcall.Stepto(-45671, -16154, -1509);
		gcall.Stepto(-45757, -16340, -1513);
		gcall.Stepto(-45844, -16574, -1503);
		gcall.Stepto(-45902, -16745, -1489);
		//Sleep(2000);
		//gcall.FindThenKill(0, 300, modeNormal | modeAoe | modePickup);
		//gcall.Stepto(-45844, -16574, -1503);
		//gcall.Stepto(-45902, -16745, -1489);
		Sleep(1000);
		gcall.PickupTask();
		Sleep(1000);
		gcall.Stepto(-46070, -16733, -1548);
		gcall.Stepto(-46260, -16719, -1592);
		gcall.Stepto(-46336, -16842, -1610);
		gcall.Stepto(-46337, -16844, -1610);
		//Sleep(2000);
		//gcall.FindThenKill(0, 300, modeNormal | modeAoe | modePickup);
		//gcall.Stepto(-46260, -16719, -1592);
		//gcall.Stepto(-46337, -16844, -1610);
		Sleep(1000);
		gcall.PickupTask();
		Sleep(1000);
		gcall.Stepto(-46441, -16769, -1619);
		gcall.Stepto(-46650, -16636, -1616);
		gcall.Stepto(-46873, -16692, -1608);
		gcall.Stepto(-46906, -16755, -1609);
		gcall.Stepto(-46906, -16777, -1611);
		//Sleep(2000);
		//gcall.FindThenKill(0, 300, modeNormal | modeAoe | modePickup);
		//gcall.Stepto(-46906, -16755, -1609);
		//gcall.Stepto(-46906, -16777, -1611);
		Sleep(1000);
		gcall.PickupTask();
		Sleep(1000);
		gcall.Stepto(-46995, -16618, -1606);
		gcall.Stepto(-47007, -16598, -1606);
		gcall.Stepto(-47095, -16586, -1616);
		gcall.Stepto(-47137, -16641, -1614);
		//Sleep(2000);
		//gcall.FindThenKill(0, 300, modeNormal | modeAoe | modePickup);
		//gcall.Stepto(-47095, -16586, -1616);
		//gcall.Stepto(-47137, -16641, -1614);
		Sleep(1000);
		gcall.PickupTask();
		gcall.NewSpend(2.5);
		gcall.Stepto(-47184, -16592, -1616);
		gcall.Stepto(-47357, -16416, -1630);
		gcall.Stepto(-47531, -16238, -1619);
		gcall.Stepto(-47751, -16131, -1613);
		gcall.Stepto(-47988, -16060, -1615);
		gcall.Stepto(-48226, -15989, -1607);
		gcall.Stepto(-48468, -15943, -1603);
		gcall.Stepto(-48713, -15983, -1609);
		gcall.Stepto(-48947, -16064, -1612);
		gcall.Stepto(-49039, -16139, -1608);
		gcall.Stepto(-49115, -16297, -1609);
		gcall.Stepto(-49224, -16463, -1607);
		gcall.Stepto(-49318, -16637, -1607);
		gcall.Stepto(-49411, -16812, -1609);
		gcall.NewSpend(1);
		gcall.Stepto(-49506, -16991, -1586);
		gcall.Stepto(-49599, -17166, -1520);
		gcall.Stepto(-49692, -17341, -1485);
		gcall.Stepto(-49785, -17517, -1492);
		gcall.Stepto(-49878, -17692, -1495);
		gcall.Stepto(-49971, -17867, -1496);
		gcall.Stepto(-50064, -18043, -1496);
		gcall.Stepto(-50167, -18212, -1496);
		gcall.Stepto(-50293, -18366, -1494);
		gcall.Stepto(-50428, -18516, -1494);
		gcall.Stepto(-50561, -18663, -1494);
		gcall.Stepto(-50694, -18811, -1494);
		gcall.Stepto(-50746, -18869, -1494);
		gcall.FindThenKill(0, 500, modeNormal | modeAoe | modeGoback | modePickup | modeTask,2);
		Sleep(2000);
		gcall.HeChengWuQi(EQUITMENT_POS::WUQI);
		Sleep(1000);
		gcall.FenJieByConfig();
		Sleep(1000);
		gcall.SortBag();
		break;
	case 3:
		gcall.NewSpend(2.5);
		gcall.Stepto(-50746, -18869, -1494);
		gcall.Stepto(-50640, -18726, -1494);
		gcall.Stepto(-50522, -18567, -1494);
		gcall.Stepto(-50405, -18407, -1494);
		gcall.Stepto(-50291, -18244, -1494);
		gcall.Stepto(-50182, -18079, -1496);
		gcall.Stepto(-50072, -17913, -1496);
		gcall.Stepto(-49971, -17743, -1496);
		gcall.Stepto(-49874, -17569, -1493);
		gcall.Stepto(-49846, -17519, -1493);
		gcall.Stepto(-49806, -17452, -1492);
		gcall.Stepto(-49675, -17241, -1489);
		gcall.Stepto(-49544, -17031, -1568);
		gcall.Stepto(-49414, -16822, -1610);
		gcall.Stepto(-49283, -16611, -1607);
		gcall.Stepto(-49184, -16451, -1608);
		gcall.Stepto(-49161, -16413, -1609);
		gcall.Stepto(-48984, -16243, -1609);
		gcall.Stepto(-48772, -16114, -1615);
		gcall.Stepto(-48539, -16030, -1604);
		gcall.Stepto(-48296, -16006, -1607);
		gcall.Stepto(-48055, -16061, -1615);
		gcall.Stepto(-47816, -16129, -1615);
		gcall.Stepto(-47578, -16197, -1614);
		gcall.Stepto(-47335, -16243, -1627);
		gcall.Stepto(-47087, -16243, -1611);
		gcall.Stepto(-46839, -16243, -1602);
		gcall.Stepto(-46591, -16242, -1604);
		gcall.Stepto(-46343, -16242, -1588);
		gcall.Stepto(-46096, -16260, -1563);
		gcall.Stepto(-45864, -16346, -1524);
		gcall.Stepto(-45649, -16470, -1487);
		gcall.Stepto(-45443, -16610, -1450);
		gcall.Stepto(-45238, -16751, -1437);
		gcall.Stepto(-45033, -16891, -1443);
		gcall.Stepto(-44830, -17034, -1355);
		gcall.Stepto(-44656, -17165, -1269);
		gcall.Stepto(-44498, -17286, -1174);
		gcall.Stepto(-44341, -17407, -1097);
		gcall.Stepto(-44184, -17528, -1011);
		gcall.Stepto(-44024, -17645, -941);
		gcall.Stepto(-43858, -17755, -934);
		gcall.Stepto(-43693, -17864, -935);
		gcall.Stepto(-43527, -17973, -934);
		gcall.Stepto(-43361, -18082, -935);
		gcall.Stepto(-43193, -18193, -935);
		gcall.Stepto(-43027, -18302, -935);
		gcall.Stepto(-42861, -18412, -936);
		gcall.Stepto(-42696, -18521, -933);
		gcall.Stepto(-42530, -18630, -937);
		gcall.Stepto(-42364, -18739, -935);
		gcall.Stepto(-42202, -18853, -933);
		gcall.Stepto(-42053, -18985, -933);
		gcall.Stepto(-41905, -19116, -933);
		gcall.Stepto(-41756, -19248, -929);
		gcall.Stepto(-41608, -19380, -928);
		gcall.Stepto(-41460, -19512, -930);
		gcall.Stepto(-41311, -19644, -933);
		gcall.Stepto(-41158, -19769, -928);
		gcall.Stepto(-41003, -19893, -929);
		gcall.Stepto(-40848, -20017, -931);
		gcall.Stepto(-40690, -20143, -933);
		gcall.Stepto(-40537, -20265, -935);
		gcall.Stepto(-40382, -20389, -935);
		gcall.Stepto(-40227, -20513, -933);
		gcall.Stepto(-40065, -20632, -933);
		gcall.Stepto(-39903, -20747, -939);
		gcall.Stepto(-39743, -20865, -963);
		gcall.Stepto(-39582, -20980, -1018);
		gcall.Stepto(-39421, -21096, -1105);
		gcall.Stepto(-39259, -21211, -1191);
		gcall.Stepto(-39098, -21327, -1258);
		gcall.Stepto(-38937, -21442, -1326);
		gcall.Stepto(-38777, -21560, -1374);
		gcall.Stepto(-38665, -21722, -1411);
		gcall.Stepto(-38602, -21909, -1445);
		gcall.Stepto(-38599, -22106, -1475);
		gcall.Stepto(-38655, -22293, -1463);
		gcall.Stepto(-38742, -22475, -1423);
		gcall.Stepto(-38830, -22653, -1365);
		gcall.Stepto(-38917, -22831, -1338);
		gcall.NewSpend(1);
		Sleep(5000);
		gcall.Stepto(-38935, -22867, -1331);
		gcall.WaitPlans();
		gcall.Stepto(-39042, -23085, -1375);
		gcall.WaitPlans();
		gcall.Stepto(-39137, -23316, -1371);
		gcall.WaitPlans();
		gcall.NewSpend(2.5);
		gcall.Stepto(-39173, -23563, -1389);
		gcall.Stepto(-39104, -23799, -1395);
		gcall.Stepto(-38970, -24007, -1410);
		gcall.Stepto(-38781, -24164, -1457);
		gcall.Stepto(-38574, -24303, -1511);
		gcall.Stepto(-38368, -24441, -1546);
		gcall.Stepto(-38161, -24580, -1553);
		gcall.Stepto(-37958, -24724, -1537);
		gcall.Stepto(-37781, -24901, -1532);
		gcall.Stepto(-37607, -25078, -1526);
		gcall.Stepto(-37434, -25255, -1512);
		gcall.Stepto(-37260, -25432, -1504);
		gcall.Stepto(-37088, -25612, -1496);
		gcall.Stepto(-36944, -25814, -1477);
		gcall.Stepto(-36792, -26011, -1442);
		gcall.Stepto(-36629, -26198, -1400);
		gcall.Stepto(-36490, -26403, -1368);
		gcall.Stepto(-36351, -26607, -1360);
		gcall.Stepto(-36212, -26813, -1369);
		gcall.Stepto(-36073, -27019, -1402);
		gcall.Stepto(-35923, -27217, -1393);
		gcall.Stepto(-35744, -27390, -1377);
		gcall.Stepto(-35544, -27535, -1354);
		gcall.Stepto(-35327, -27636, -1341);
		gcall.Stepto(-35076, -27692, -1331);
		gcall.Stepto(-34826, -27708, -1313);
		gcall.Stepto(-34582, -27692, -1294);
		gcall.Stepto(-34335, -27657, -1284);
		gcall.Stepto(-34096, -27586, -1269);
		gcall.Stepto(-33859, -27507, -1230);
		gcall.Stepto(-33626, -27428, -1191);
		gcall.Stepto(-33390, -27348, -1176);
		gcall.Stepto(-33158, -27262, -1169);
		gcall.Stepto(-32929, -27166, -1161);
		gcall.Stepto(-32696, -27068, -1160);
		gcall.Stepto(-32471, -26965, -1162);
		gcall.Stepto(-32247, -26858, -1155);
		gcall.Stepto(-32036, -26736, -1148);
		gcall.Stepto(-31824, -26603, -1144);
		gcall.Stepto(-31618, -26457, -1123);
		gcall.Stepto(-31418, -26315, -1100);
		gcall.Stepto(-31213, -26171, -1084);
		gcall.Stepto(-31000, -26045, -1008);
		gcall.Stepto(-30777, -25936, -994);
		gcall.Stepto(-30584, -25845, -990);
		gcall.Stepto(-30678, -25728, -991);
		gcall.NewSpend(1);
		Sleep(1000);
		gcall.DeliverQuests(346, 5,L"육지평");
		Sleep(1000);
		gcall.DeliverQuests(307,taskid,L"기봉사");
		Sleep(2000);
		break;
	case 4:
		gcall.LinQuJiangLi();
		Sleep(1000);
		gcall.JiaBaoShi(0, L"거와의 삼각 자수정");
		Sleep(1000);
		//Lianji6_go();
		//while (true)
		//{
			//_BAGSTU goods;
			//gcall.GetGoodsByEquipPos(EQUITMENT_POS::WUQI, &goods);

			////如果等级5, 而且经验满
			//if (goods.m_DangQianJingYanZhi == goods.m_DangQianJingYanZongZhi)
			//{
			//	if (goods.m_PingJi == 5 ||
			//		goods.m_PingJi == 10)
			//	{
			//		log(_T("洪门已经满级,准备突破5"));//洪门武器已满
			//		//gcall.WearEquipment(L"천령도끼 1단계", EQUITMENT_POS::WUQI);
			//		//Sleep(500);
			//		//gcall.WearEquipment(L"천령도끼 2단계", EQUITMENT_POS::WUQI);
			//		//Sleep(500);
			//		//gcall.WearEquipment(L"천령도끼 3단계", EQUITMENT_POS::WUQI);
			//		//Sleep(500);
			//		//gcall.WearEquipment(L"천령도끼 4단계", EQUITMENT_POS::WUQI);
			//		//Sleep(500);
			//		//gcall.WearEquipment(L"천령도끼 5단계", EQUITMENT_POS::WUQI);
			//		//Sleep(500);
			//		//gcall.HeChengWuQi(EQUITMENT_POS::WUQI);
			//		//Sleep(2000);
			//		//gcall.HeChengWuQiByHun(EQUITMENT_POS::WUQI);
			//		//Sleep(2000);
			//		gcall.HeChengWuQi_Po5(EQUITMENT_POS::WUQI, L"천령도끼");
			//		Sleep(2000);
			//		/*				gcall.LinQuJiangLi();
			//						Sleep(2000);
			//						gcall.JiaBaoShi(0, L"삼각 자수정");
			//						Sleep(2000);*/
			//		//break;
			//		Lianji6();
			//	}
			//	else
			//	{
			//		Lianji6();
			//	}
			//}else
			//{
			//	Lianji6();
			//}
			//if (gcall.GetPlayerLevel()>5)
			//{
				//break;
			//}
			//else
			//{
				//Lianji6();
			//}
			//Sleep(100);
		//}
		//MessageBox(0, L"6级完", 0, MB_OK);
		//while (true)
		//{
			//DWORD pStartAddr = gcall.GetTaskStartAddr();//获取任务开始地址
			//DWORD info = gcall.GetPresentTaskIndexes(0, pStartAddr);//获得当前做到第几个小任务
			//if (info > 4)
			//{
			//	break;
			//}
			gcall.NewSpend(2.5);
			gcall.Stepto(-39093, -23304, -1370);
			gcall.Stepto(-39158, -23480, -1363);
			gcall.Stepto(-39210, -23658, -1403);
			gcall.Stepto(-39166, -23838, -1395);
			gcall.Stepto(-39101, -24012, -1396);
			gcall.Stepto(-38953, -24124, -1422);
			gcall.Stepto(-38787, -24210, -1463);
			gcall.Stepto(-38618, -24289, -1501);
			gcall.Stepto(-38447, -24363, -1536);
			gcall.Stepto(-38273, -24429, -1550);
			gcall.Stepto(-38096, -24488, -1545);
			gcall.Stepto(-37925, -24545, -1519);
			gcall.Stepto(-37757, -24601, -1496);
			gcall.Stepto(-37577, -24649, -1480);
			gcall.Stepto(-37397, -24695, -1469);
			gcall.Stepto(-37215, -24735, -1459);
			gcall.Stepto(-37032, -24772, -1450);
			gcall.Stepto(-36849, -24808, -1457);
			gcall.Stepto(-36665, -24844, -1448);
			gcall.Stepto(-36483, -24881, -1421);
			gcall.Stepto(-36300, -24917, -1381);
			gcall.Stepto(-36116, -24952, -1341);
			gcall.Stepto(-35932, -24978, -1309);
			gcall.Stepto(-35743, -24990, -1283);
			gcall.Stepto(-35560, -24956, -1255);
			gcall.Stepto(-35378, -24917, -1250);
			gcall.Stepto(-35197, -24877, -1231);
			gcall.Stepto(-35019, -24822, -1210);
			gcall.Stepto(-34839, -24762, -1201);
			gcall.Stepto(-34660, -24701, -1191);
			gcall.Stepto(-34474, -24688, -1183);
			gcall.Stepto(-34291, -24723, -1181);
			gcall.Stepto(-34111, -24769, -1178);
			gcall.Stepto(-33929, -24815, -1164);
			gcall.Stepto(-33748, -24857, -1148);
			gcall.Stepto(-33566, -24897, -1136);
			gcall.Stepto(-33385, -24940, -1124);
			gcall.Stepto(-33203, -24983, -1103);
			gcall.Stepto(-33021, -25026, -1084);
			gcall.Stepto(-32840, -25068, -1068);
			gcall.Stepto(-32658, -25111, -1055);
			gcall.Stepto(-32475, -25154, -1045);
			gcall.Stepto(-32294, -25196, -1042);
			gcall.Stepto(-32111, -25234, -1035);
			gcall.Stepto(-31927, -25267, -1028);
			gcall.Stepto(-31744, -25301, -1021);
			gcall.Stepto(-31559, -25334, -1014);
			gcall.Stepto(-31376, -25367, -1004);
			gcall.Stepto(-31192, -25401, -997);
			gcall.Stepto(-31008, -25434, -990);
			gcall.Stepto(-30825, -25471, -986);
			gcall.Stepto(-30645, -25522, -991);
			gcall.Stepto(-30514, -25604, -991);
			gcall.NewSpend(1);
			Sleep(1000);
			gcall.SellItemByConfig(L"이화상");
			Sleep(1000);
			gcall.NewSpend(2.5);
			gcall.Stepto(-30461,-25703,-991);
			gcall.Stepto(-30577,-25290,-972);
			gcall.Stepto(-30620,-25042,-957);
			gcall.Stepto(-30661,-24794,-972);
			gcall.Stepto(-30671,-24542,-990);
			gcall.Stepto(-30629,-24295,-997);
			gcall.Stepto(-30584,-24048,-989);
			gcall.Stepto(-30539,-23801,-983);
			gcall.Stepto(-30493,-23552,-989);
			gcall.Stepto(-30448,-23304,-1004);
			gcall.Stepto(-30400,-23056,-1021);
			gcall.Stepto(-30348,-22811,-1031);
			gcall.Stepto(-30281,-22569,-1032);
			gcall.Stepto(-30189,-22335,-1030);
			gcall.Stepto(-30053,-22124,-1002);
			gcall.Stepto(-29903,-21920,-962);
			gcall.Stepto(-29747,-21722,-935);
			gcall.Stepto(-29592,-21524,-922);
			gcall.NewSpend(1);
			gcall.Stepto(-29437,-21328,-911);
			gcall.Stepto(-29271,-21141,-901);
			gcall.Stepto(-29068,-20994,-883);
			//gcall.NewSpend(1);
			/*过滤怪物(야생곰, 1);
			过滤怪物(흑룡채 보초병, 2);*/ //现在没有过滤怪物先不用
			gcall.FindThenKill(0, 1000, modeNormal | modeAoe | modePickup);
			//gcall.NewSpend(2.5);
			gcall.Stepto(-28851,-20901,-851);
			gcall.Stepto(-28651,-20872,-831);
			gcall.Stepto(-28450,-20858,-819);
			gcall.Stepto(-28249,-20845,-805);
			gcall.Stepto(-28050,-20824,-779);
			gcall.Stepto(-27849,-20803,-756);
			gcall.Stepto(-27648,-20781,-733);
			gcall.Stepto(-27449,-20759,-728);
			gcall.Stepto(-27249,-20684,-734);
			gcall.Stepto(-27103,-20529,-726);
			gcall.Stepto(-26976,-20374,-733);
			gcall.Stepto(-26804,-20202,-735);
			gcall.Stepto(-26633,-20095,-735);
			gcall.Stepto(-26654,-19884,-735);
			//gcall.NewSpend(1);
			gcall.FindThenKill(0, 450, modeNormal | modeAoe | modePickup);
			gcall.Stepto(-26845,-20027,-735);
			gcall.Stepto(-27045,-20177,-735);
			gcall.Stepto(-27247,-20328,-732);
			gcall.Stepto(-27449,-20480,-735);
			gcall.Stepto(-27692,-20392,-759);
			gcall.Stepto(-27906,-20262,-794);
			gcall.Stepto(-28118,-20128,-820);
			gcall.Stepto(-28331,-19994,-834);
			gcall.Stepto(-28544,-19859,-841);
			gcall.Stepto(-28756,-19724,-861);
			gcall.Stepto(-28958,-19579,-901);
			gcall.Stepto(-29147,-19414,-915);
			gcall.Stepto(-29336,-19248,-909);
			gcall.Stepto(-29527,-19081,-901);
			gcall.Stepto(-29716,-18916,-896);
			gcall.Stepto(-29906,-18750,-902);
			gcall.Stepto(-30100,-18580,-920);
			gcall.Stepto(-30289,-18415,-940);
			gcall.Stepto(-30496,-18466,-950);
			gcall.Stepto(-30558,-18710,-932);
			gcall.Stepto(-30658,-18938,-906);
			gcall.Stepto(-30812,-19136,-899);
			gcall.Stepto(-30954,-19341,-914);

			gcall.FindThenKill(0, 450, modeNormal | modeAoe | modePickup);
			//gcall.NewSpend(2.5);
			gcall.Stepto(-31068,-19132,-873);
			gcall.Stepto(-31164,-18956,-853);
			gcall.Stepto(-31260,-18779,-851);
			gcall.Stepto(-31390,-18614,-832);
			gcall.Stepto(-31534,-18440,-825);
			gcall.Stepto(-31666,-18288,-825);
			gcall.Stepto(-31800,-18138,-825);

			//gcall.NewSpend(1);
			gcall.FindThenKill(0, 450, modeNormal | modeAoe | modePickup);
			gcall.Stepto(-31722,-18325,-825);
			gcall.Stepto(-31635,-18560,-825);
			gcall.Stepto(-31547,-18796,-826);
			gcall.Stepto(-31460,-19032,-828);
			gcall.Stepto(-31578,-19210,-827);
			gcall.Stepto(-31804,-19315,-843);
			gcall.Stepto(-32028,-19429,-861);
			gcall.Stepto(-32242,-19563,-839);
			gcall.Stepto(-32349,-19733,-842);
			gcall.Stepto(-32379,-19984,-856);
			gcall.Stepto(-32409,-20184,-864);
			gcall.Stepto(-32435,-20404,-875);
			gcall.Stepto(-32454,-20640,-875);
			gcall.Stepto(-32460,-20892,-883);
			gcall.Stepto(-32454,-21142,-913);
			Sleep(2000);
			gcall.FindThenKill(0, 300, modeNormal | modeAoe | modePickup);
			gcall.NewSpend(2.5);
			gcall.Stepto(-32398,-21364,-933);
			gcall.Stepto(-32284,-21529,-954);
			gcall.Stepto(-32173,-21698,-986);
			gcall.Stepto(-32043,-21911,-1024);
			gcall.Stepto(-31948,-22090,-1022);
			gcall.Stepto(-31851,-22277,-1015);
			gcall.Stepto(-31733,-22501,-1008);
			gcall.Stepto(-31617,-22724,-1004);
			gcall.Stepto(-31500,-22946,-1009);
			gcall.Stepto(-31383,-23170,-1025);
			gcall.Stepto(-31267,-23392,-1010);
			gcall.Stepto(-31151,-23615,-977);
			gcall.Stepto(-31034,-23836,-955);
			gcall.NewSpend(1);
			gcall.randXianlu(0);
			Sleep(1000);
			//任务需改，暂时没想好逻辑怎么写。
		//}
		break;
	case 5:
		gcall.NewSpend(2.5);
		gcall.Stepto(-31579, -22062, -1028,10,20,3000);
		gcall.Stepto(-31537, -21821, -1041);
		gcall.Stepto(-31480, -21586, -1025);
		gcall.Stepto(-31365, -21366, -1000);
		gcall.Stepto(-31254, -21143, -974);
		gcall.Stepto(-31259, -20895, -956);
		gcall.Stepto(-31292, -20648, -941);
		gcall.Stepto(-31327, -20402, -926);
		gcall.Stepto(-31362, -20156, -912);
		gcall.Stepto(-31385, -19910, -904);
		gcall.Stepto(-31259, -19697, -914);
		gcall.Stepto(-31134, -19482, -917);
		gcall.Stepto(-31011, -19273, -902);
		gcall.Stepto(-30903, -19104, -890);
		gcall.Stepto(-30796, -18932, -900);
		gcall.Stepto(-30690, -18761, -924);
		gcall.Stepto(-30559, -18550, -944);
		gcall.Stepto(-30433, -18345, -954);
		gcall.Stepto(-30303, -18131, -960);
		gcall.Stepto(-30182, -17914, -950);
		gcall.Stepto(-30071, -17724, -921);
		gcall.Stepto(-29944, -17510, -865);
		gcall.Stepto(-29817, -17296, -821);
		gcall.Stepto(-29690, -17081, -782);
		gcall.Stepto(-29594, -16890, -733);
		gcall.Stepto(-29561, -16643, -685);
		gcall.Stepto(-29562, -16395, -689);
		gcall.NewSpend(1);
		Sleep(5000);
		gcall.Stepto(-29576, -16167, -704);
		gcall.WaitPlans();
		gcall.Stepto(-29592, -15967, -717);
		gcall.WaitPlans();
		gcall.NewSpend(2.5);
		gcall.Stepto(-29610, -15759, -738);
		gcall.Stepto(-29641, -15513, -813);
		gcall.Stepto(-29668, -15266, -927);
		gcall.Stepto(-29695, -15018, -1070);
		gcall.Stepto(-29722, -14772, -1215);
		gcall.Stepto(-29748, -14525, -1258);
		gcall.Stepto(-29772, -14277, -1308);
		gcall.Stepto(-29795, -14030, -1389);
		gcall.Stepto(-29819, -13783, -1499);
		gcall.Stepto(-29843, -13536, -1588);
		gcall.Stepto(-29868, -13289, -1666);
		gcall.Stepto(-29952, -13103, -1709);
		gcall.NewSpend(1);
		Sleep(1000);
		gcall.DeliverQuests(307, taskid, L"기봉사");
		Sleep(1000);
		break;
	}

}

void TaskScript::Task_308(int taskid)
{
	int i;//执行次数
	i = 0;
	switch (taskid)
	{
	case 1:
		/*gcall.JieFengHezi(L"잠긴 천령무기",0,L"제룡림 열쇠",1);
		MessageBox(0, L"摇奖完", L"装八卦", MB_OK);*/
		//这里应该摇奖，但是只执行一次，先判断背包里是否还有 L"천령강시의 정수" 如果已经没有了，就不执行这里了。
		_BAGSTU jingqi;
		while (gcall.GetGoodsFromBagByName(L"천령강시의 정수", &jingqi))
		{
			gcall.CityConvey(2);
			Sleep(2000);
			gcall.Stepto(-35888, -38107, -374);
			gcall.Stepto(-35639, -38093, -374);
			gcall.Stepto(-35389, -38080, -374);
			gcall.Stepto(-35141, -38098, -374);
			Sleep(1000);
			gcall.HeChengWuQi(EQUITMENT_POS::WUQI);
			Sleep(1000);
			gcall.SellItemByConfig(L"무료한");//问题
			Sleep(1000);
			gcall.Stepto(-35021, -38264, -374);
			gcall.Stepto(-34927, -38496, -374);
			gcall.Stepto(-34788, -38701, -374);
			gcall.Yaojiang(L"천령강시의 정수", L"천령보패");
			gcall.Stepto(-34787, -38701, -374);
			gcall.Stepto(-34903, -38493, -374);
			gcall.Stepto(-35032, -38280, -374);
			gcall.Stepto(-35120, -38097, -374);
			gcall.SellItemByConfig(L"무료한");
			Sleep(1000);
		}
		gcall.NewSpend(2.5);
		gcall.Stepto(-35275, -37916, -374);
		gcall.Stepto(-35327, -37677, -373);
		gcall.Stepto(-35249, -37443, -379);
		gcall.Stepto(-35140, -37220, -386);
		gcall.Stepto(-35040, -36993, -413);
		gcall.Stepto(-34966, -36757, -462);
		gcall.Stepto(-34956, -36510, -515);
		gcall.Stepto(-35029, -36275, -593);
		gcall.Stepto(-35201, -36097, -662);
		gcall.Stepto(-35390, -35936, -760);
		gcall.Stepto(-35545, -35744, -863);
		gcall.Stepto(-35507, -35529, -923);
		gcall.Stepto(-35275, -35447, -960);
		gcall.Stepto(-35030, -35410, -1011);
		gcall.Stepto(-34782, -35397, -1044);
		gcall.Stepto(-34536, -35372, -1061);
		gcall.Stepto(-34296, -35311, -1090);
		gcall.Stepto(-34093, -35173, -1123);
		gcall.Stepto(-34052, -34932, -1153);
		gcall.Stepto(-34138, -34698, -1169);
		gcall.Stepto(-34214, -34462, -1164);
		gcall.Stepto(-34239, -34215, -1169);
		gcall.Stepto(-34232, -33967, -1214);
		gcall.Stepto(-34203, -33721, -1293);
		gcall.Stepto(-34165, -33476, -1350);
		gcall.Stepto(-34107, -33235, -1375);
		gcall.Stepto(-34043, -32995, -1391);
		gcall.Stepto(-33979, -32752, -1389);
		gcall.Stepto(-33913, -32503, -1414);
		gcall.Stepto(-33850, -32264, -1441);
		gcall.Stepto(-33783, -32025, -1441);
		gcall.Stepto(-33715, -31786, -1420);
		gcall.Stepto(-33647, -31548, -1378);
		gcall.Stepto(-33578, -31309, -1360);
		gcall.Stepto(-33510, -31071, -1373);
		gcall.Stepto(-33441, -30833, -1387);
		gcall.Stepto(-33373, -30594, -1401);
		gcall.Stepto(-33304, -30356, -1396);
		gcall.Stepto(-33236, -30118, -1365);
		gcall.Stepto(-33167, -29879, -1302);
		gcall.Stepto(-33098, -29640, -1274);
		gcall.Stepto(-33029, -29401, -1267);
		gcall.Stepto(-32961, -29163, -1262);
		gcall.Stepto(-32892, -28924, -1256);
		gcall.Stepto(-32823, -28686, -1254);
		gcall.Stepto(-32739, -28451, -1255);
		gcall.Stepto(-32594, -28248, -1259);
		gcall.Stepto(-32473, -28031, -1251);
		gcall.Stepto(-32356, -27810, -1238);
		gcall.Stepto(-32240, -27590, -1228);
		gcall.Stepto(-32130, -27367, -1216);
		gcall.Stepto(-32022, -27144, -1203);
		gcall.Stepto(-31915, -26920, -1182);
		gcall.Stepto(-31810, -26696, -1156);
		gcall.Stepto(-31722, -26464, -1122);
		gcall.Stepto(-31641, -26229, -1095);
		gcall.Stepto(-31562, -25994, -1073);
		gcall.Stepto(-31479, -25760, -1041);
		gcall.Stepto(-31395, -25527, -1015);
		gcall.Stepto(-31311, -25293, -998);
		gcall.Stepto(-31227, -25060, -987);
		gcall.Stepto(-31143, -24826, -976);
		gcall.Stepto(-31059, -24593, -969);
		gcall.Stepto(-30975, -24357, -964);
		gcall.Stepto(-30891, -24123, -960);
		gcall.Stepto(-30807, -23890, -961);
		gcall.Stepto(-30723, -23656, -973);
		gcall.Stepto(-30639, -23423, -995);
		gcall.Stepto(-30555, -23189, -1013);
		gcall.Stepto(-30471, -22955, -1022);
		gcall.Stepto(-30391, -22721, -1030);
		gcall.Stepto(-30310, -22486, -1037);
		gcall.Stepto(-30230, -22252, -1030);
		gcall.Stepto(-30148, -22016, -1006);
		gcall.Stepto(-30056, -21785, -979);
		gcall.Stepto(-29964, -21555, -958);
		gcall.Stepto(-29873, -21324, -940);
		gcall.Stepto(-29782, -21094, -929);
		gcall.Stepto(-29690, -20863, -912);
		gcall.Stepto(-29599, -20631, -903);
		gcall.Stepto(-29507, -20400, -898);
		gcall.Stepto(-29440, -20162, -897);
		gcall.Stepto(-29426, -19914, -904);
		gcall.Stepto(-29436, -19667, -907);
		gcall.Stepto(-29456, -19419, -906);
		gcall.Stepto(-29478, -19172, -901);
		gcall.Stepto(-29511, -18927, -911);
		gcall.Stepto(-29539, -18680, -921);
		gcall.Stepto(-29565, -18433, -920);
		gcall.Stepto(-29597, -18182, -897);
		gcall.Stepto(-29631, -17936, -869);
		gcall.Stepto(-29664, -17689, -830);
		gcall.Stepto(-29669, -17442, -800);
		gcall.Stepto(-29658, -17194, -788);
		gcall.Stepto(-29633, -16947, -749);
		gcall.Stepto(-29607, -16700, -711);
		gcall.Stepto(-29581, -16454, -685);
		gcall.Stepto(-29579,-16269, -697);
		Sleep(5000);
		gcall.Stepto(-29579, -16229, -700);
		gcall.Stepto(-29596,-16126, -706);

		gcall.WaitPlans();
		gcall.NewSpend(1);
		/*
		gcall.Stepto(-29611,-15857,-732);
		gcall.Stepto(-29626,-15608,-775);
		gcall.Stepto(-29640,-15360,-882);
		gcall.Stepto(-29661,-15113,-1009);
		gcall.Stepto(-29683,-14866,-1167);
		gcall.Stepto(-29703,-14618,-1244);
		gcall.Stepto(-29723,-14371,-1293);
		gcall.Stepto(-29744,-14124,-1353);
		gcall.Stepto(-29764,-13876,-1456);
		gcall.Stepto(-29784,-13627,-1548);
		gcall.Stepto(-29805,-13380,-1633);
		gcall.Stepto(-29825,-13131,-1706);
		gcall.Stepto(-29845,-12884,-1750);
		gcall.Stepto(-30001,-12720,-1789);
		gcall.Stepto(-30216,-12591,-1819);
		gcall.Stepto(-30460,-12519,-1788);
		gcall.Stepto(-30708,-12543,-1728);
		gcall.Stepto(-30955,-12569,-1676);
		gcall.Stepto(-31202,-12597,-1676);
		gcall.Stepto(-31451,-12624,-1685);
		gcall.Stepto(-31655,-12679,-1682);
		gcall.Stepto(-31823,-12862,-1676);
		gcall.Stepto(-31983,-13051,-1676);
		gcall.Stepto(-32038,-13291,-1677);
		gcall.Stepto(-32055,-13539,-1676);
		gcall.Stepto(-32061,-13787,-1675);
		gcall.Stepto(-32089,-14032,-1675);
		gcall.Stepto(-32223,-14240,-1675);
		gcall.Stepto(-32444,-14343,-1675);
		gcall.Stepto(-32693,-14353,-1679);
		gcall.Stepto(-32945,-14346,-1650);
		gcall.Stepto(-33194,-14345,-1704);
		gcall.Stepto(-33442,-14342,-1704);
		gcall.Stepto(-33690,-14343,-1704);
		gcall.Stepto(-33938,-14343,-1704);
		gcall.Stepto(-34187,-14345,-1704);
		gcall.Stepto(-34435,-14349,-1704);
		gcall.Stepto(-34686,-14354,-1704);
		gcall.Stepto(-34934,-14357,-1704);
		gcall.Stepto(-35182,-14363,-1704);
		gcall.Stepto(-35429,-14353,-1704);
		gcall.Stepto(-35647,-14238,-1709);
		gcall.Stepto(-35725,-14008,-1716);
		gcall.Stepto(-35730,-13758,-1716);
		gcall.Stepto(-35728,-13510,-1716);
		gcall.Stepto(-35726,-13258,-1709);
		gcall.Stepto(-35726,-13009,-1713);
		gcall.Stepto(-35802,-12775,-1713);
		gcall.Stepto(-35973,-12598,-1713);
		gcall.Stepto(-36188,-12469,-1713);
		gcall.Stepto(-36429,-12412,-1713);
		gcall.Stepto(-36679,-12412,-1707);
		gcall.Stepto(-36928,-12416,-1582);
		gcall.Stepto(-37177,-12417,-1430);
		gcall.Stepto(-37426,-12418,-1416);
		gcall.Stepto(-37676,-12419,-1416);
		gcall.Stepto(-37925,-12420,-1411);
		gcall.Stepto(-38176,-12419,-1411);
		gcall.Stepto(-38424,-12418,-1409);
		gcall.Stepto(-38673,-12417,-1409);
		gcall.Stepto(-38921,-12415,-1409);
		*/
		Sleep(1000);
		gcall.Shunyi(L"1-9-1");
		Sleep(2000);
		gcall.Stepto(-38305, -12425, -1411);
		gcall.Stepto(-38509, -12426, -1409);
		gcall.Stepto(-38710, -12423, -1409);
		gcall.Stepto(-38947, -12418, -1409);
		gcall.FindThenKill(0, 600, modeNormal | modeAoe | modePickup);
		Sleep(4000);
		break;
	case 2:
		gcall.Stepto(-39052, -12237, -1409);
		gcall.Stepto(-39249, -12029, -1409);
		gcall.Stepto(-39506, -11897, -1416);
		Sleep(500);
		gcall.PickupTask();
		Sleep(500);
		gcall.Stepto(-39308, -11900, -1416);
		Sleep(1000);
		gcall.Shunyi(L"1-9-2");
		Sleep(4000);
		gcall.Stepto(-29590, -16033, -713);
		gcall.Stepto(-29566, -16394, -689);
		break;
	case 3:
		/*gcall.NewSpend(2);
		gcall.Stepto(-38879, -12426, -1409);
		gcall.Stepto(-38631, -12434, -1409);
		gcall.Stepto(-38383, -12442, -1411);
		gcall.Stepto(-38335, -12444, -1411);
		gcall.Stepto(-38253, -12449, -1411);
		gcall.Stepto(-38005, -12452, -1411);
		gcall.Stepto(-37757, -12454, -1414);
		gcall.Stepto(-37509, -12456, -1416);
		gcall.Stepto(-37261, -12458, -1416);
		gcall.Stepto(-37014, -12461, -1529);
		gcall.Stepto(-36766, -12460, -1680);
		gcall.Stepto(-36518, -12445, -1707);
		gcall.Stepto(-36271, -12430, -1713);
		gcall.Stepto(-36040, -12508, -1713);
		gcall.Stepto(-35857, -12668, -1713);
		gcall.Stepto(-35744, -12888, -1713);
		gcall.Stepto(-35704, -13130, -1706);
		gcall.Stepto(-35692, -13377, -1712);
		gcall.Stepto(-35690, -13625, -1716);
		gcall.Stepto(-35689, -13874, -1716);
		gcall.Stepto(-35677, -14121, -1709);
		gcall.Stepto(-35517, -14297, -1709);
		gcall.Stepto(-35287, -14387, -1704);
		gcall.Stepto(-35040, -14402, -1704);
		gcall.Stepto(-34792, -14405, -1704);
		gcall.Stepto(-34544, -14406, -1704);
		gcall.Stepto(-34296, -14407, -1704);
		gcall.Stepto(-34048, -14408, -1704);
		gcall.Stepto(-33800, -14398, -1704);
		gcall.Stepto(-33553, -14379, -1704);
		gcall.Stepto(-33306, -14361, -1704);
		gcall.Stepto(-33059, -14342, -1650);
		gcall.Stepto(-32811, -14324, -1650);
		gcall.Stepto(-32564, -14305, -1675);
		gcall.Stepto(-32327, -14230, -1675);
		gcall.Stepto(-32157, -14054, -1675);
		gcall.Stepto(-32071, -13821, -1673);
		gcall.Stepto(-31997, -13585, -1679);
		gcall.Stepto(-31941, -13343, -1678);
		gcall.Stepto(-31882, -13102, -1676);
		gcall.Stepto(-31769, -12881, -1676);
		gcall.Stepto(-31589, -12711, -1687);
		gcall.Stepto(-31389, -12564, -1680);
		gcall.Stepto(-31160, -12470, -1676);
		gcall.Stepto(-30914, -12469, -1684);
		gcall.Stepto(-30667, -12492, -1740);
		gcall.Stepto(-30421, -12514, -1792);
		gcall.Stepto(-30177, -12564, -1819);
		gcall.Stepto(-29972, -12694, -1792);
		gcall.Stepto(-29865, -12914, -1747);
		gcall.Stepto(-29806, -13154, -1698);
		gcall.Stepto(-29770, -13400, -1621);
		gcall.Stepto(-29745, -13646, -1536);
		gcall.Stepto(-29759, -13898, -1447);
		gcall.Stepto(-29774, -14146, -1344);
		gcall.Stepto(-29755, -14393, -1290);
		gcall.Stepto(-29732, -14640, -1242);
		gcall.Stepto(-29709, -14884, -1159);
		gcall.Stepto(-29685, -15135, -999);
		gcall.Stepto(-29661, -15382, -874);
		gcall.Stepto(-29638, -15628, -768);
		gcall.Stepto(-29614, -15875, -731);
		gcall.Stepto(-29591, -16120, -707);
		gcall.NewSpend(1);
		gcall.Stepto(-29575, -16292, -696);
		gcall.WaitPlans();
		gcall.Stepto(-29565, -16407, -688);
		gcall.WaitPlans();
		gcall.Stepto(-29562, -16655, -691);
		gcall.NewSpeed(1);
		*/
		lianji8_go();

		while (true)
		{
			if (gcall.GetPlayerLevel()<8)
			{
				lianji8();
			}else
			{
				break;
			}
			//if (gcall.GetPlayerLevel()>9)
			//{
			//	
			//	i++;
			//	if (i > 3)
			//	{
			//		//貌似韩服改了，没这些了。
			//		gcall.JieFengZhuangBei(L"봉인된 제룡목걸이", L"제룡 봉인해제 부적", 1);
			//		Sleep(1000);
			//		gcall.WearEquipment(L"제룡목걸이 1단계", 7);
			//		Sleep(1000);
			//		gcall.JieFengZhuangBei(L"봉인된 제룡반지", L"제룡 봉인해제 부적", 1);
			//		Sleep(1000);
			//		gcall.WearEquipment(L"제룡반지 1단계", 6);
			//		Sleep(1000);
			//		gcall.JieFengZhuangBei(L"봉인된 제룡귀걸이", L"제룡 봉인해제 부적", 1);
			//		Sleep(1000);
			//		gcall.WearEquipment(L"제룡귀걸이 1단계", 3);
			//		Sleep(1000);
			//		break;
			//	}
			//	else
			//	{
			//		lianji8();
			//	}
			//}
			//else
			//{
			//	lianji8();
			//}

		}
		gcall.NewSpend(2.5);
		gcall.Stepto(-29571, -16902, -734);
		gcall.Stepto(-29582, -17151, -771);
		gcall.Stepto(-29583, -17397, -776);
		gcall.Stepto(-29569, -17645, -798);
		gcall.Stepto(-29554, -17891, -841);
		gcall.Stepto(-29539, -18142, -882);
		gcall.Stepto(-29524, -18391, -912);
		gcall.Stepto(-29509, -18635, -924);
		gcall.Stepto(-29493, -18887, -915);
		gcall.Stepto(-29478, -19134, -902);
		gcall.Stepto(-29463, -19382, -904);
		gcall.Stepto(-29448, -19626, -909);
		gcall.Stepto(-29432, -19875, -904);
		gcall.Stepto(-29428, -19945, -903);
		gcall.Stepto(-29425, -20035, -900);
		gcall.Stepto(-29464, -20280, -897);
		gcall.Stepto(-29571, -20499, -899);
		gcall.Stepto(-29782, -20628, -914);
		gcall.Stepto(-29999, -20750, -931);
		gcall.Stepto(-30202, -20890, -948);
		gcall.Stepto(-30369, -21077, -964);
		gcall.Stepto(-30510, -21276, -979);
		gcall.Stepto(-30628, -21495, -998);
		gcall.Stepto(-30697, -21737, -1028);
		gcall.Stepto(-30753, -21977, -1051);
		gcall.Stepto(-30807, -22209, -1058);
		gcall.Stepto(-30808, -22211, -1058);
		gcall.Stepto(-30833, -22315, -1053);
		gcall.Stepto(-30914, -22551, -1048);
		gcall.Stepto(-30996, -22785, -1055);
		gcall.Stepto(-31077, -23017, -1050);
		gcall.Stepto(-31139, -23258, -1024);
		gcall.Stepto(-31144, -23508, -990);
		gcall.Stepto(-31146, -23753, -963);
		gcall.Stepto(-31149, -24005, -946);
		gcall.Stepto(-31152, -24250, -942);
		gcall.Stepto(-31151, -24499, -961);
		gcall.Stepto(-31136, -24747, -974);
		gcall.Stepto(-31120, -24994, -979);
		gcall.Stepto(-31074, -25239, -984);
		gcall.Stepto(-30991, -25474, -991);
		gcall.Stepto(-30835, -25662, -991);
		gcall.Stepto(-30606, -25765, -991);
		gcall.Stepto(-30522, -25796, -990);
		gcall.NewSpend(1);
		Sleep(1000);
		gcall.DeliverQuests(308,taskid,L"기봉사");
		Sleep(1000);
		gcall.SellItemByConfig(L"이화상");
		Sleep(1000);
		gcall.SortBag();
		Sleep(1000);
		break;
	case 4:
		gcall.NewSpend(2.5);
		gcall.Stepto(-29582, -16456, -684);
		gcall.Stepto(-29587, -16512, -680);
		gcall.Stepto(-29662, -16746, -715);
		gcall.Stepto(-29764, -16974, -779);
		gcall.Stepto(-29851, -17205, -817);
		gcall.Stepto(-29940, -17438, -857);
		gcall.Stepto(-30028, -17671, -907);
		gcall.Stepto(-30116, -17904, -944);
		gcall.Stepto(-30199, -18136, -960);
		gcall.Stepto(-30127, -18351, -943);
		gcall.Stepto(-30010, -18571, -923);
		gcall.Stepto(-29915, -18799, -895);
		gcall.Stepto(-29836, -19035, -882);
		gcall.Stepto(-29766, -19271, -890);
		gcall.Stepto(-29695, -19508, -905);
		gcall.Stepto(-29622, -19745, -909);
		gcall.Stepto(-29546, -19981, -906);
		gcall.Stepto(-29471, -20218, -898);
		gcall.Stepto(-29542, -20445, -899);
		gcall.Stepto(-29712, -20627, -909);
		gcall.Stepto(-29808, -20849, -922);
		gcall.Stepto(-29861, -21092, -939);
		gcall.Stepto(-29910, -21338, -943);
		gcall.Stepto(-29958, -21584, -959);
		gcall.Stepto(-30005, -21825, -976);
		gcall.Stepto(-30052, -22070, -998);
		gcall.Stepto(-30100, -22315, -1021);
		gcall.Stepto(-30147, -22557, -1033);
		gcall.Stepto(-30195, -22802, -1033);
		gcall.Stepto(-30243, -23046, -1023);
		gcall.Stepto(-30290, -23290, -1005);
		gcall.Stepto(-30337, -23530, -994);
		gcall.Stepto(-30385, -23775, -989);
		gcall.Stepto(-30431, -24011, -996);
		gcall.Stepto(-30480, -24261, -1004);
		gcall.Stepto(-30527, -24506, -993);
		gcall.Stepto(-30574, -24750, -973);
		gcall.Stepto(-30611, -24996, -958);
		gcall.Stepto(-30615, -25244, -971);
		gcall.Stepto(-30621, -25493, -991);
		gcall.Stepto(-30621, -25570, -991);
		gcall.NewSpend(1);
		Sleep(2000);
		gcall.FixWuqi();
		Sleep(1000);
		gcall.NewSpend(2.5);
		gcall.Stepto(-30621, -25570, -991);
		gcall.Stepto(-30622, -25571, -991);
		gcall.Stepto(-30823, -25702, -991);
		gcall.Stepto(-30987, -25886, -997);
		gcall.Stepto(-31070, -26122, -1046);
		gcall.Stepto(-31088, -26366, -1117);
		gcall.Stepto(-31074, -26614, -1149);
		gcall.Stepto(-31036, -26859, -1161);
		gcall.Stepto(-30995, -27103, -1189);
		gcall.Stepto(-30977, -27216, -1191);
		gcall.Stepto(-30967, -27273, -1192);
		gcall.Stepto(-30927, -27516, -1199);
		gcall.Stepto(-30886, -27761, -1198);
		gcall.Stepto(-30846, -28004, -1194);
		gcall.Stepto(-30805, -28252, -1186);
		gcall.Stepto(-30764, -28497, -1183);
		gcall.Stepto(-30723, -28740, -1182);
		gcall.Stepto(-30814, -28941, -1195);
		gcall.Stepto(-30992, -29106, -1216);
		gcall.Stepto(-31173, -29276, -1234);
		gcall.Stepto(-31355, -29447, -1234);
		gcall.Stepto(-31535, -29615, -1268);
		gcall.Stepto(-31716, -29785, -1279);
		gcall.Stepto(-31899, -29955, -1288);
		gcall.Stepto(-32084, -30121, -1294);
		gcall.Stepto(-32276, -30275, -1304);
		gcall.Stepto(-32469, -30432, -1313);
		gcall.Stepto(-32661, -30586, -1324);
		gcall.Stepto(-32855, -30742, -1335);
		gcall.Stepto(-33049, -30899, -1344);
		gcall.Stepto(-33243, -31055, -1350);
		gcall.Stepto(-33435, -31210, -1353);
		gcall.Stepto(-33630, -31364, -1369);
		gcall.Stepto(-33823, -31513, -1427);
		gcall.Stepto(-33947, -31609, -1439);
		gcall.Stepto(-33955, -31691, -1433);
		gcall.Stepto(-33976, -31934, -1439);
		gcall.Stepto(-33999, -32187, -1442);
		gcall.Stepto(-34021, -32433, -1437);
		gcall.Stepto(-34043, -32680, -1403);
		gcall.Stepto(-34065, -32928, -1399);
		gcall.Stepto(-34087, -33176, -1378);
		gcall.Stepto(-34109, -33424, -1345);
		gcall.Stepto(-34131, -33670, -1288);
		gcall.Stepto(-34153, -33917, -1204);
		gcall.Stepto(-34204, -34161, -1168);
		gcall.Stepto(-34268, -34402, -1168);
		gcall.Stepto(-34331, -34640, -1201);
		gcall.Stepto(-34389, -34882, -1159);
		gcall.Stepto(-34441, -35126, -1086);
		gcall.Stepto(-34598, -35297, -1061);
		gcall.Stepto(-34836, -35367, -1039);
		gcall.Stepto(-35081, -35414, -1002);
		gcall.Stepto(-35301, -35521, -943);
		gcall.Stepto(-35401, -35728, -839);
		gcall.Stepto(-35329, -35951, -742);
		gcall.Stepto(-35232, -36209, -616);
		gcall.Stepto(-35159, -36444, -505);
		gcall.Stepto(-35137, -36690, -437);
		gcall.Stepto(-35182, -36936, -394);
		gcall.Stepto(-35320, -37136, -379);
		gcall.Stepto(-35500, -37311, -379);
		gcall.Stepto(-35692, -37470, -379);
		gcall.Stepto(-35900, -37600, -362);
		gcall.Stepto(-36120, -37721, -373);
		gcall.Stepto(-36337, -37836, -376);
		gcall.Stepto(-36562, -37952, -358);
		gcall.Stepto(-36784, -38059, -379);
		gcall.Stepto(-36859, -38095, -378);
		gcall.NewSpend(1);
		Sleep(1000);
		gcall.DeliverQuests(308,taskid,L"역기산");
		Sleep(2000);
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;

	}
}

void TaskScript::Task_309(int taskid)
{
	switch (taskid)
	{
	case 1:
		gcall.NewSpend(2.5);
		gcall.Stepto(-36861,-38091,-378);
		gcall.Stepto(-36823,-38076,-378);
		gcall.Stepto(-36591,-37987,-360);
		gcall.Stepto(-36357,-37897,-374);
		gcall.Stepto(-36126,-37807,-373);
		gcall.Stepto(-35896,-37719,-359);
		gcall.Stepto(-35665,-37629,-376);
		gcall.Stepto(-35446,-37513,-379);
		gcall.Stepto(-35255,-37355,-379);
		gcall.Stepto(-35065,-37196,-394);
		gcall.Stepto(-34865,-37050,-417);
		gcall.Stepto(-34645,-36936,-437);
		gcall.Stepto(-34420,-36833,-445);
		gcall.Stepto(-34183,-36761,-555);
		gcall.Stepto(-33941,-36712,-913);
		gcall.Stepto(-33710,-36746,-1120);
		gcall.Stepto(-33535,-36921,-1174);
		gcall.Stepto(-33402,-37130,-1202);
		gcall.Stepto(-33285,-37349,-1233);
		gcall.Stepto(-33173,-37570,-1247);
		gcall.Stepto(-33061,-37791,-1264);
		gcall.Stepto(-32949,-38013,-1295);
		gcall.Stepto(-32802,-38209,-1332);
		gcall.Stepto(-32619,-38376,-1348);
		gcall.Stepto(-32433,-38539,-1351);
		gcall.Stepto(-32231,-38680,-1365);
		gcall.Stepto(-32015,-38800,-1382);
		gcall.Stepto(-31773,-38851,-1407);
		gcall.Stepto(-31527,-38887,-1414);
		gcall.Stepto(-31280,-38910,-1432);
		gcall.Stepto(-31034,-38932,-1456);
		gcall.Stepto(-30786,-38954,-1500);
		gcall.Stepto(-30539,-38976,-1527);
		gcall.Stepto(-30292,-38987,-1539);
		gcall.Stepto(-30049,-38937,-1530);
		gcall.Stepto(-29806,-38885,-1516);
		gcall.Stepto(-29562,-38855,-1505);
		gcall.Stepto(-29329,-38937,-1499);
		gcall.Stepto(-29109,-39039,-1502);
		gcall.Stepto(-28880,-39146,-1513);
		gcall.Stepto(-28653,-39252,-1536);
		gcall.Stepto(-28428,-39357,-1547);
		gcall.Stepto(-28204,-39462,-1540);
		gcall.Stepto(-27979,-39567,-1522);
		gcall.Stepto(-27755,-39672,-1509);
		gcall.Stepto(-27530,-39777,-1531);
		gcall.Stepto(-27311,-39893,-1536);
		gcall.Stepto(-27104,-40030,-1552);
		gcall.Stepto(-26899,-40174,-1573);
		gcall.Stepto(-26698,-40319,-1616);
		gcall.Stepto(-26500,-40469,-1648);
		gcall.Stepto(-26303,-40620,-1664);
		gcall.Stepto(-26112,-40777,-1704);
		gcall.Stepto(-25921,-40940,-1748);
		gcall.NewSpend(1);
		Sleep(5000);
		gcall.Stepto(-25838,-41011,-1764);
		gcall.WaitPlans();
		gcall.Stepto(-25680,-41146,-1800);
		gcall.WaitPlans();
		gcall.Stepto(-25491,-41308,-1869);
		gcall.WaitPlans();
		gcall.NewSpend(2.5);
		gcall.Stepto(-25271,-41422,-1922);
		gcall.Stepto(-25038,-41507,-1978);
		gcall.Stepto(-24796,-41540,-2039);
		gcall.Stepto(-24544,-41550,-2101);
		gcall.Stepto(-24296,-41560,-2142);
		gcall.Stepto(-24050,-41570,-2189);
		gcall.Stepto(-23802,-41580,-2222);
		gcall.Stepto(-23554,-41589,-2244);
		gcall.Stepto(-23305,-41599,-2269);
		gcall.Stepto(-23057,-41609,-2273);
		gcall.Stepto(-22808,-41618,-2268);
		gcall.Stepto(-22559,-41628,-2296);
		gcall.Stepto(-22316,-41657,-2320);
		gcall.Stepto(-22089,-41760,-2327);
		gcall.Stepto(-21870,-41876,-2341);
		gcall.Stepto(-21670,-42025,-2342);
		gcall.Stepto(-21484,-42186,-2345);
		gcall.Stepto(-21306,-42361,-2351);
		gcall.Stepto(-21131,-42536,-2368);
		gcall.Stepto(-20959,-42717,-2411);
		gcall.Stepto(-20801,-42909,-2463);
		gcall.Stepto(-20645,-43100,-2524);
		gcall.Stepto(-20485,-43293,-2590);
		gcall.Stepto(-20309,-43464,-2643);
		gcall.Stepto(-20148,-43620,-2677);
		gcall.Stepto(-20005,-43757,-2703);
		gcall.Stepto(-19868,-43901,-2730);
		gcall.Stepto(-19740,-44054,-2752);
		gcall.Stepto(-19617,-44210,-2763);
		gcall.Stepto(-19494,-44365,-2782);
		gcall.Stepto(-19334,-44479,-2798);
		gcall.Stepto(-19140,-44514,-2820);
		gcall.Stepto(-18942,-44481,-2834);
		gcall.Stepto(-18753,-44419,-2817);
		gcall.Stepto(-18748,-44417,-2816);
		gcall.NewSpend(1);
		Sleep(1000);
		break;
	case 2:
		gcall.FindThenKill(0,300,modeNormal | modeAoe | modeTask,2);
		Sleep(1000);
		break;
	case 3:
		gcall.Stepto(-18748,-44417,-2816);
		gcall.DeliverQuests(309,taskid,L"고봉");
		Sleep(1000);
		break;
	case 4:
		gcall.NewSpend(2.5);
		gcall.Stepto(-18791,-44556,-2826);
		gcall.Stepto(-18889,-44589,-2832);
		gcall.Stepto(-19124,-44667,-2824);
		gcall.Stepto(-19359,-44745,-2823);
		gcall.Stepto(-19595,-44823,-2819);
		gcall.Stepto(-19830,-44902,-2813);
		gcall.Stepto(-20065,-44980,-2789);
		gcall.Stepto(-20128,-45001,-2785);
		gcall.Stepto(-20343,-44917,-2783);
		gcall.Stepto(-20570,-44962,-2795);
		gcall.Stepto(-20750,-45046,-2806);
		gcall.Stepto(-20924,-45140,-2812);
		gcall.Stepto(-21097,-45238,-2812);
		gcall.Stepto(-21266,-45334,-2819);
		gcall.Stepto(-21451,-45439,-2826);
		gcall.Stepto(-21671,-45508,-2826);
		gcall.Stepto(-21868,-45534,-2821);
		gcall.Stepto(-22065,-45560,-2810);
		gcall.Stepto(-22261,-45586,-2803);
		gcall.Stepto(-22458,-45612,-2793);
		gcall.Stepto(-22671,-45639,-2782);
		gcall.Stepto(-22917,-45671,-2776);
		gcall.Stepto(-23142,-45769,-2759);
		gcall.Stepto(-23351,-45898,-2750);
		gcall.Stepto(-23541,-46055,-2795);
		gcall.Stepto(-23705,-46242,-2828);
		gcall.Stepto(-23837,-46452,-2857);
		gcall.Stepto(-23958,-46669,-2889);
		gcall.NewSpend(1);
		gcall.Stepto(-24064,-46893,-2900);
		gcall.Stepto(-24105,-46981,-2902);
		Sleep(1000);
		gcall.PickupTask();
		Sleep(1000);
		break;
	case 5:
		gcall.Stepto(-24105,-46981,-2902);
		gcall.Stepto(-24255,-46903,-2896);
		gcall.Stepto(-24474,-46787,-2882);
		gcall.Stepto(-24532,-46757,-2881);
		gcall.Stepto(-24638,-46567,-2884);
		gcall.Stepto(-24702,-46329,-2888);
		gcall.Stepto(-24705,-46262,-2890);
		Sleep(3000);
		gcall.KeyPress(27);
		Sleep(3000);
		break;
	case 6:
		gcall.Stepto(-24681,-46255,-2889);
		Sleep(1000);
		gcall.DeliverQuests(309,taskid,L"범박",1);
		break;
	case 7:
		gcall.Stepto(-24708,-46264,-2889);
		gcall.Stepto(-24622,-46442,-2885);
		gcall.Stepto(-24479,-46643,-2881);
		gcall.Stepto(-24304,-46819,-2890);
		gcall.Stepto(-24200,-46923,-2897);
		gcall.Stepto(-24180,-46931,-2899);
		Sleep(1000);
		gcall.PickupTask();//pickuptask不行。类似8级副本的问题。
		Sleep(5000);
		break;
	case 8:
		gcall.PickupTask();
		//可能掉出副本
		gcall.Stepto(-25694,-41184,-1806);
		gcall.NewSpend(2.5);
		gcall.Stepto(-25756,-41224,-1803);
		gcall.Stepto(-25542,-41323,-1863);
		gcall.Stepto(-25342,-41406,-1910);
		gcall.Stepto(-25112,-41497,-1965);
		gcall.Stepto(-24875,-41571,-2030);
		gcall.Stepto(-24628,-41596,-2097);
		gcall.Stepto(-24381,-41604,-2145);
		gcall.Stepto(-24133,-41601,-2180);
		gcall.Stepto(-23885,-41598,-2224);
		gcall.Stepto(-23637,-41595,-2232);
		gcall.Stepto(-23389,-41594,-2262);
		gcall.Stepto(-23141,-41594,-2275);
		gcall.Stepto(-22893,-41595,-2269);
		gcall.Stepto(-22645,-41597,-2289);
		gcall.Stepto(-22398,-41623,-2315);
		gcall.Stepto(-22167,-41719,-2322);
		gcall.Stepto(-21970,-41868,-2338);
		gcall.Stepto(-21773,-42019,-2343);
		gcall.Stepto(-21576,-42170,-2341);
		gcall.Stepto(-21377,-42325,-2348);
		gcall.Stepto(-21203,-42501,-2364);
		gcall.Stepto(-21033,-42682,-2397);
		gcall.Stepto(-20866,-42864,-2449);
		gcall.Stepto(-20709,-43056,-2507);
		gcall.Stepto(-20554,-43250,-2573);
		gcall.Stepto(-20421,-43459,-2634);
		gcall.Stepto(-20318,-43685,-2683);
		gcall.Stepto(-20220,-43912,-2722);
		gcall.Stepto(-20128,-44143,-2760);
		gcall.Stepto(-20077,-44384,-2789);
		gcall.Stepto(-20155,-44615,-2783);
		gcall.Stepto(-20349,-44766,-2779);
		gcall.Stepto(-20567,-44884,-2799);
		gcall.Stepto(-20785,-45002,-2806);
		gcall.Stepto(-21004,-45119,-2805);
		gcall.Stepto(-21222,-45237,-2811);
		gcall.Stepto(-21448,-45337,-2819);
		gcall.Stepto(-21689,-45396,-2823);
		gcall.Stepto(-21933,-45441,-2821);
		gcall.Stepto(-22177,-45487,-2815);
		gcall.Stepto(-22420,-45533,-2798);
		gcall.Stepto(-22662,-45586,-2783);
		gcall.Stepto(-22899,-45660,-2777);
		gcall.Stepto(-23129,-45751,-2761);
		gcall.Stepto(-23354,-45856,-2750);
		gcall.Stepto(-23545,-46013,-2794);
		gcall.Stepto(-23719,-46190,-2826);
		gcall.Stepto(-23883,-46375,-2856);
		gcall.Stepto(-24048,-46561,-2888);
		gcall.Stepto(-24215,-46747,-2890);
		gcall.Stepto(-24382,-46929,-2892);
		gcall.Stepto(-24579,-47081,-2895);
		gcall.NewSpend(1);
		//可能掉出副本
		gcall.Stepto(-24200,-46923,-2897);
		gcall.Stepto(-24142,-46854,-2897);
		gcall.Stepto(-23981,-46664,-2891);
		gcall.Stepto(-23821,-46475,-2857);
		gcall.Stepto(-23660,-46285,-2827);
		gcall.Stepto(-23500,-46095,-2788);
		gcall.Stepto(-23319,-45928,-2751);
		gcall.Stepto(-23116,-45783,-2761);
		gcall.Stepto(-22915,-45638,-2777);
		gcall.Stepto(-22713,-45494,-2781);
		gcall.Stepto(-22513,-45350,-2799);
		gcall.Stepto(-22320,-45194,-2821);
		gcall.Stepto(-22252,-44965,-2821);
		gcall.FindThenKill(0,450,modeNormal | modeAoe | modePickup);
		gcall.Stepto(-22191,-44948,-2823);
		gcall.Stepto(-22241,-44924,-2821);
		Sleep(1000);
		log(_T("准备开第一个门"));
		gcall.PickupTask();
		Sleep(1000);
		gcall.FindThenKill(0,450,modeNormal | modeAoe | modePickup);
		gcall.Stepto(-22191,-44948,-2823);
		gcall.Stepto(-22241,-44924,-2821);
		Sleep(1000);
		log(_T("准备开第一个门"));
		gcall.PickupTask();
		Sleep(1000);
		//gcall.Stepto(-22375,-44806,-2789);
		gcall.DeliverQuests(309,taskid,L"하준광");
		Sleep(6000);
		//gcall.Stepto(-22230 ,-44953 ,-2822); 
		break;
	case 9:
		fPosition mypos;
		fPosition movepos1;
		movepos1.x = -47126;
		movepos1.y = -18847;
		movepos1.z = -2846;
		fPosition movepos2;
		movepos2.x = -46541;
		movepos2.y = -17737;
		movepos2.z = -2846;
		fPosition movepos3;
		movepos3.x = -47513;
		movepos3.y = -16227;
		movepos3.z = -2863;
		fPosition movepos4;
		movepos4.x = -46048;
		movepos4.y = -15698;
		movepos4.z = -2876;
		fPosition movepos4_1;
		movepos4_1.x = -46001;
		movepos4_1.y = -16407;
		movepos4_1.z = -2857;
		fPosition movepos5;
		movepos5.x = -46238;
		movepos5.y = -14097;
		movepos5.z = -2865;
		fPosition movepos6;
		movepos6.x = -46635;
		movepos6.y = -15107;
		movepos6.z = -2877;
		while (1)
		{

			gcall.GetPlayerPos(&mypos);
			if (gcall.CalcC(mypos,movepos1)<200)
			{
				gcall.FindThenKill(0,400,modeNormal | modeAoe | modePickup );
				gcall.Stepto(-18960,-47184,-2846);
				gcall.Stepto(-18978,-47374,-2852);
				Sleep(1000);
				gcall.PickupSpecTypeTask(200,0x20,L"폭탄 부품상자");
				Sleep(2000);
				gcall.Stepto(-18978,-47374,-2852);
				gcall.Stepto(-18960,-47184,-2846);
			}else if (gcall.CalcC(mypos,movepos2)<200)
			{
				gcall.FindThenKill(0,400,modeNormal | modeAoe | modePickup );
				gcall.Stepto(-17701,-46701,-2845);
				gcall.Stepto(-17737,-46541,-2846);
				Sleep(1000);
				gcall.PickupSpecTypeTask(200,0x20,L"폭탄 부품상자");
				Sleep(2000);
			}else if (gcall.CalcC(mypos,movepos3)<200)
			{
				gcall.FindThenKill(0,400,modeNormal | modeAoe | modePickup );
				gcall.Stepto(-16227,-47513,-2863);
				Sleep(1000);
				gcall.PickupSpecTypeTask(200,0x20,L"폭탄 부품상자");
				Sleep(2000);
			}else if (gcall.CalcC(mypos,movepos4)<200)
			{
				gcall.FindThenKill(0,200,modeNormal | modeAoe | modePickup );
				gcall.Stepto(-15437,-46112,-2877);
				gcall.Stepto(-15591,-45918,-2877);
				gcall.Stepto(-15965,-45849,-2860);
				gcall.Stepto(-16189,-45987,-2857);
				gcall.Stepto(-16391,-46020,-2857);
				Sleep(1000);
				gcall.PickupSpecTypeTask(200,0x20,L"폭약통");
				Sleep(2000);
			}else if (gcall.CalcC(mypos,movepos4_1)<150)
			{
				gcall.Stepto(-15437,-46112,-2877);
				gcall.Stepto(-15591,-45918,-2877);
				gcall.Stepto(-15965,-45849,-2860);
				gcall.Stepto(-16189,-45987,-2857);
				gcall.Stepto(-16391,-46020,-2857);
				Sleep(1000);
				gcall.PickupSpecTypeTask(200,0x20,L"폭약통");
				Sleep(2000);
			}
			else if (gcall.CalcC(mypos,movepos5)<200)
			{
				gcall.FindThenKill(0,210,modeNormal | modeAoe | modePickup );
				gcall.Stepto(-14097,-46238 ,-2865);
				gcall.Stepto(-13800,-46253,-2877);
				Sleep(1000);
				gcall.PickupSpecTypeTask(200,0x20,L"폭약통");
				Sleep(1000);
				gcall.Stepto(-14097,-46238 ,-2865);
				gcall.Stepto(-14234,-46139 ,-2862);
				Sleep(2000);
			}else if (gcall.CalcC(mypos,movepos6)<200)
			{
				gcall.FindThenKill(0,900,modeNormal | modeAoe | modePickup );
				Sleep(1000);
				gcall.Stepto(-15129,-46716,-2877);
				gcall.Stepto(-15079,-46579,-2877);
				Sleep(1000);
				log(_T("准备捡第六个物品"));
				gcall.PickupSpecTypeTask(200,0x20,L"기폭장치");
				Sleep(5000);
				gcall.FindThenKill(0,600,modeNormal | modeAoe | modePickup);
				gcall.Stepto(-15129,-46716,-2877);
				gcall.Stepto(-15079,-46579,-2877);
				Sleep(1000);
				gcall.PickupSpecTypeTask(200,0x20,L"기폭장치");
				Sleep(5000);
				gcall.FindThenKill(0,600,modeNormal | modeAoe | modePickup);
				gcall.Stepto(-15129,-46716,-2877);
				gcall.Stepto(-15079,-46579,-2877);
				Sleep(1000);
				gcall.PickupSpecTypeTask(200,0x20,L"기폭장치");
				Sleep(2000);
				DWORD pStartAddr = gcall.GetTaskStartAddr();//获取任务开始地址
				DWORD info = gcall.GetPresentTaskIndexes(0, pStartAddr);//获得当前做到第几个小任务
				if (info != 9)
				{
					break;
				}
			}
			gcall.Stepto(L"하준광");
			if(gcall.GetRangeMonsterCount(200) >= 1){
				gcall.FindThenKill(0,200,modeNormal | modeAoe | modePickup );
			}
			
		}
		

		


		while (1)
		{
			fPosition mypos;
			fPosition movepos;
			movepos.x = -47081;
			movepos.y = -24579;
			movepos.z = -2895;
			gcall.GetPlayerPos(&mypos);
			if (gcall.CalcC(mypos,movepos)<300)
			{
				break;
			}else
			{
				gcall.NewSpend(2.5);
				gcall.Stepto(-15184,-46661,-2877,10,5,5000);
				gcall.Stepto(-15406,-46738,-2877);
				gcall.Stepto(-15641,-46815,-2877);
				gcall.Stepto(-15878,-46889,-2859);
				gcall.Stepto(-16118,-46954,-2860);
				gcall.Stepto(-16360,-47010,-2862);
				gcall.Stepto(-16602,-47065,-2861);
				gcall.Stepto(-16843,-47121,-2859);
				gcall.Stepto(-17087,-47169,-2865);
				gcall.Stepto(-17334,-47172,-2867);
				gcall.Stepto(-17582,-47167,-2854);
				gcall.Stepto(-17829,-47146,-2851);
				gcall.Stepto(-18073,-47102,-2851);
				gcall.Stepto(-18307,-47021,-2853);
				gcall.Stepto(-18526,-46904,-2852);
				gcall.Stepto(-18742,-46783,-2847);
				gcall.Stepto(-18932,-46624,-2848);
				gcall.Stepto(-19100,-46442,-2854);
				gcall.Stepto(-19256,-46250,-2848);
				gcall.Stepto(-19357,-46024,-2844);
				gcall.Stepto(-19444,-45792,-2843);
				gcall.Stepto(-19530,-45559,-2830);
				gcall.Stepto(-19615,-45326,-2825);
				gcall.Stepto(-19701,-45093,-2828);
				gcall.Stepto(-19787,-44861,-2814);
				gcall.Stepto(-19873,-44628,-2806);
				gcall.Stepto(-19959,-44395,-2796);
				gcall.Stepto(-20044,-44163,-2768);
				gcall.Stepto(-20131,-43930,-2732);
				gcall.Stepto(-20246,-43711,-2690);
				gcall.Stepto(-20388,-43504,-2646);
				gcall.Stepto(-20550,-43308,-2587);
				gcall.Stepto(-20721,-43117,-2523);
				gcall.Stepto(-20895,-42924,-2460);
				gcall.Stepto(-21063,-42736,-2406);
				gcall.Stepto(-21230,-42553,-2369);
				gcall.Stepto(-21403,-42374,-2351);
				gcall.Stepto(-21581,-42202,-2341);
				gcall.Stepto(-21779,-42053,-2342);
				gcall.Stepto(-21988,-41919,-2341);
				gcall.Stepto(-22205,-41800,-2328);
				gcall.Stepto(-22425,-41685,-2311);
				gcall.Stepto(-22649,-41578,-2290);
				gcall.Stepto(-22894,-41549,-2277);
				gcall.Stepto(-23142,-41538,-2275);
				gcall.Stepto(-23390,-41528,-2256);
				gcall.Stepto(-23638,-41533,-2226);
				gcall.Stepto(-23886,-41547,-2217);
				gcall.Stepto(-24133,-41564,-2171);
				gcall.Stepto(-24380,-41585,-2139);
				gcall.Stepto(-24632,-41607,-2099);
				gcall.Stepto(-24882,-41612,-2041);
				gcall.Stepto(-25118,-41537,-1969);
				gcall.Stepto(-25335,-41417,-1913);
				gcall.Stepto(-25564,-41322,-1860);
				gcall.NewSpend(1);
				gcall.Stepto(-25791,-41225,-1797);
				Sleep(5000);
				gcall.Stepto(-26152,-40934,-1724);
				Sleep(5000);
				gcall.FenJieByConfig();
				//修理
				_BAGSTU stu;
				gcall.GetGoodsByEquipPos(EQUITMENT_POS::WUQI, &stu);
				if (stu.m_Lasting < 10)
				{
					gcall.NewSpend(2.5);
					gcall.Stepto(-26132,-40920,-1726);
					gcall.Stepto(-26307,-40764,-1689);
					gcall.Stepto(-26459,-40633,-1667);
					gcall.Stepto(-26646,-40470,-1641);
					gcall.Stepto(-26834,-40308,-1597);
					gcall.Stepto(-27021,-40146,-1560);
					gcall.Stepto(-27209,-39984,-1548);
					gcall.Stepto(-27402,-39828,-1533);
					gcall.Stepto(-27603,-39683,-1509);
					gcall.Stepto(-27824,-39571,-1505);
					gcall.Stepto(-28059,-39493,-1529);
					gcall.Stepto(-28303,-39447,-1547);
					gcall.Stepto(-28546,-39399,-1552);
					gcall.Stepto(-28790,-39351,-1538);
					gcall.Stepto(-29033,-39303,-1519);
					gcall.Stepto(-29276,-39255,-1516);
					gcall.Stepto(-29520,-39207,-1519);
					gcall.Stepto(-29763,-39159,-1524);
					gcall.Stepto(-30006,-39111,-1528);
					gcall.Stepto(-30254,-39062,-1537);
					gcall.Stepto(-30498,-39014,-1528);
					gcall.Stepto(-30742,-38966,-1507);
					gcall.Stepto(-30986,-38918,-1466);
					gcall.Stepto(-31232,-38869,-1442);
					gcall.Stepto(-31475,-38821,-1415);
					gcall.Stepto(-31719,-38760,-1413);
					gcall.Stepto(-31954,-38682,-1385);
					gcall.Stepto(-32185,-38590,-1366);
					gcall.Stepto(-32390,-38451,-1353);
					gcall.Stepto(-32578,-38290,-1346);
					gcall.Stepto(-32744,-38107,-1327);
					gcall.Stepto(-32889,-37905,-1295);
					gcall.Stepto(-33005,-37686,-1274);
					gcall.Stepto(-33110,-37461,-1262);
					gcall.Stepto(-33217,-37234,-1247);
					gcall.Stepto(-33323,-37008,-1221);
					gcall.Stepto(-33429,-36782,-1207);
					gcall.Stepto(-33534,-36557,-1196);
					gcall.Stepto(-33640,-36332,-1174);
					gcall.Stepto(-33745,-36107,-1153);
					gcall.Stepto(-33850,-35883,-1136);
					gcall.Stepto(-33956,-35658,-1123);
					gcall.Stepto(-34105,-35467,-1116);
					gcall.Stepto(-34329,-35357,-1086);
					gcall.Stepto(-34576,-35350,-1059);
					gcall.Stepto(-34821,-35389,-1041);
					gcall.Stepto(-35066,-35432,-1001);
					gcall.Stepto(-35306,-35493,-947);
					gcall.Stepto(-35537,-35592,-909);
					gcall.Stepto(-35554,-35798,-843);
					gcall.Stepto(-35368,-35961,-749);
					gcall.Stepto(-35184,-36127,-650);
					gcall.Stepto(-35028,-36319,-580);
					gcall.Stepto(-34953,-36555,-500);
					gcall.Stepto(-34970,-36801,-454);
					gcall.Stepto(-35030,-37041,-410);
					gcall.Stepto(-35110,-37277,-385);
					gcall.Stepto(-35190,-37512,-379);
					gcall.Stepto(-35269,-37747,-374);
					gcall.Stepto(-35293,-37993,-374);
					gcall.Stepto(-35268,-38240,-374);
					gcall.Stepto(-35096,-38393,-374);
					gcall.Stepto(-34849,-38383,-374);
					gcall.NewSpend(1);
					Sleep(1000);
					gcall.FixWuqi();
					Sleep(1000);
					gcall.NewSpend(2.5);
					gcall.Stepto(-35061,-38316,-374);
					gcall.Stepto(-35306,-38278,-374);
					gcall.Stepto(-35483,-38127,-374);
					gcall.Stepto(-35554,-37888,-374);
					gcall.Stepto(-35561,-37655,-375);
					gcall.Stepto(-35418,-37453,-379);
					gcall.Stepto(-35274,-37251,-380);
					gcall.Stepto(-35130,-37049,-398);
					gcall.Stepto(-34995,-36840,-443);
					gcall.Stepto(-34908,-36611,-492);
					gcall.Stepto(-34946,-36368,-560);
					gcall.Stepto(-35103,-36180,-627);
					gcall.Stepto(-35300,-36030,-710);
					gcall.Stepto(-35488,-35867,-809);
					gcall.Stepto(-35562,-35652,-894);
					gcall.Stepto(-35385,-35496,-938);
					gcall.Stepto(-35141,-35448,-984);
					gcall.Stepto(-34895,-35419,-1025);
					gcall.Stepto(-34647,-35411,-1047);
					gcall.Stepto(-34405,-35452,-1072);
					gcall.Stepto(-34177,-35550,-1112);
					gcall.Stepto(-33960,-35670,-1122);
					gcall.Stepto(-33784,-35842,-1144);
					gcall.Stepto(-33674,-36064,-1155);
					gcall.Stepto(-33576,-36292,-1175);
					gcall.Stepto(-33477,-36523,-1197);
					gcall.Stepto(-33379,-36751,-1212);
					gcall.Stepto(-33266,-36972,-1228);
					gcall.Stepto(-33136,-37183,-1255);
					gcall.Stepto(-33000,-37390,-1263);
					gcall.Stepto(-32842,-37581,-1269);
					gcall.Stepto(-32678,-37767,-1287);
					gcall.Stepto(-32513,-37953,-1312);
					gcall.Stepto(-32349,-38138,-1332);
					gcall.Stepto(-32184,-38324,-1345);
					gcall.Stepto(-32012,-38501,-1366);
					gcall.Stepto(-31776,-38573,-1382);
					gcall.Stepto(-31534,-38631,-1414);
					gcall.Stepto(-31293,-38689,-1439);
					gcall.Stepto(-31052,-38746,-1456);
					gcall.Stepto(-30811,-38803,-1500);
					gcall.Stepto(-30568,-38861,-1528);
					gcall.Stepto(-30326,-38919,-1539);
					gcall.Stepto(-30085,-38976,-1532);
					gcall.Stepto(-29844,-39032,-1522);
					gcall.Stepto(-29601,-39086,-1517);
					gcall.Stepto(-29354,-39141,-1509);
					gcall.Stepto(-29105,-39195,-1510);
					gcall.Stepto(-28860,-39249,-1523);
					gcall.Stepto(-28618,-39302,-1542);
					gcall.Stepto(-28375,-39356,-1546);
					gcall.Stepto(-28133,-39409,-1536);
					gcall.Stepto(-27891,-39462,-1513);
					gcall.Stepto(-27655,-39537,-1509);
					gcall.Stepto(-27459,-39686,-1526);
					gcall.Stepto(-27277,-39855,-1540);
					gcall.Stepto(-27095,-40024,-1553);
					gcall.Stepto(-26909,-40189,-1574);
					gcall.Stepto(-26723,-40352,-1619);
					gcall.Stepto(-26536,-40516,-1651);
					gcall.Stepto(-26347,-40677,-1677);
					gcall.Stepto(-26154,-40832,-1713);
					gcall.NewSpend(1);
					Sleep(5000);
				}
				gcall.Stepto(-25694,-41184,-1806);
				gcall.NewSpend(2.5);
				gcall.Stepto(-25756,-41224,-1803);
				gcall.Stepto(-25542,-41323,-1863);
				gcall.Stepto(-25342,-41406,-1910);
				gcall.Stepto(-25112,-41497,-1965);
				gcall.Stepto(-24875,-41571,-2030);
				gcall.Stepto(-24628,-41596,-2097);
				gcall.Stepto(-24381,-41604,-2145);
				gcall.Stepto(-24133,-41601,-2180);
				gcall.Stepto(-23885,-41598,-2224);
				gcall.Stepto(-23637,-41595,-2232);
				gcall.Stepto(-23389,-41594,-2262);
				gcall.Stepto(-23141,-41594,-2275);
				gcall.Stepto(-22893,-41595,-2269);
				gcall.Stepto(-22645,-41597,-2289);
				gcall.Stepto(-22398,-41623,-2315);
				gcall.Stepto(-22167,-41719,-2322);
				gcall.Stepto(-21970,-41868,-2338);
				gcall.Stepto(-21773,-42019,-2343);
				gcall.Stepto(-21576,-42170,-2341);
				gcall.Stepto(-21377,-42325,-2348);
				gcall.Stepto(-21203,-42501,-2364);
				gcall.Stepto(-21033,-42682,-2397);
				gcall.Stepto(-20866,-42864,-2449);
				gcall.Stepto(-20709,-43056,-2507);
				gcall.Stepto(-20554,-43250,-2573);
				gcall.Stepto(-20421,-43459,-2634);
				gcall.Stepto(-20318,-43685,-2683);
				gcall.Stepto(-20220,-43912,-2722);
				gcall.Stepto(-20128,-44143,-2760);
				gcall.Stepto(-20077,-44384,-2789);
				gcall.Stepto(-20155,-44615,-2783);
				gcall.Stepto(-20349,-44766,-2779);
				gcall.Stepto(-20567,-44884,-2799);
				gcall.Stepto(-20785,-45002,-2806);
				gcall.Stepto(-21004,-45119,-2805);
				gcall.Stepto(-21222,-45237,-2811);
				gcall.Stepto(-21448,-45337,-2819);
				gcall.Stepto(-21689,-45396,-2823);
				gcall.Stepto(-21933,-45441,-2821);
				gcall.Stepto(-22177,-45487,-2815);
				gcall.Stepto(-22420,-45533,-2798);
				gcall.Stepto(-22662,-45586,-2783);
				gcall.Stepto(-22899,-45660,-2777);
				gcall.Stepto(-23129,-45751,-2761);
				gcall.Stepto(-23354,-45856,-2750);
				gcall.Stepto(-23545,-46013,-2794);
				gcall.Stepto(-23719,-46190,-2826);
				gcall.Stepto(-23883,-46375,-2856);
				gcall.Stepto(-24048,-46561,-2888);
				gcall.Stepto(-24215,-46747,-2890);
				gcall.Stepto(-24382,-46929,-2892);
				gcall.Stepto(-24579,-47081,-2895);
				gcall.NewSpend(1);
				
			}
			

		}
		break;
	case 10:
		gcall.Stepto(-15077,-46574,-2877);
		gcall.Stepto(-14971,-46728,-2877);
		gcall.Stepto(-14737,-46692,-2877);
		gcall.Stepto(-14615,-46488,-2877);
		gcall.Stepto(-14597,-46236,-2877);
		gcall.Stepto(-14594,-45988,-2877);
		gcall.Stepto(-14601,-45735,-2876);
		gcall.Stepto(-14601,-45727,-2876);
		Sleep(5000);
		gcall.FindThenKill(0,600,modeNormal | modeAoe | modePickup);
		Sleep(3000);
		break;
	case 11:
		gcall.NewSpend(2.5);
		gcall.Stepto(-14661,-45805,-2877);
		gcall.Stepto(-14685,-45826,-2877);
		gcall.Stepto(-14841,-45947,-2877);
		gcall.Stepto(-15014,-46044,-2877);
		gcall.Stepto(-15187,-46140,-2877);
		gcall.Stepto(-15392,-46270,-2877);
		gcall.Stepto(-15580,-46433,-2877);
		gcall.Stepto(-15762,-46601,-2871);
		gcall.Stepto(-15944,-46770,-2860);
		gcall.Stepto(-16126,-46938,-2860);
		gcall.Stepto(-16341,-47059,-2863);
		gcall.Stepto(-16584,-47109,-2863);
		gcall.CityConvey(2);
		Sleep(3000);
		gcall.Stepto(-36188,-38116,-376);
		gcall.Stepto(-36324,-37991,-374);
		gcall.Stepto(-36459,-38020,-357);
		gcall.Stepto(-36688,-38075,-369);
		gcall.Stepto(-36866,-38110,-379);
		Sleep(1000);
		gcall.DeliverQuests(309,taskid,L"역기산");
		break;
	}
}

void TaskScript::Task_310(int taskid)
{
	switch (taskid)
	{
	case 1:
		MessageBox(0, L"310", 0, MB_OK);
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;

	}
}

/////////////////////主线结束线///////////////////////////////



/////////////////////副本分界线///////////////////////////////
void TaskScript::Lianji6_go()
{
	//进副本
	gcall.NewSpend(2.5);
	gcall.Stepto(-36188, -38116, -376);
	gcall.Stepto(-36021, -37957, -374);
	gcall.Stepto(-35842, -37786, -362);
	gcall.Stepto(-35663, -37616, -376);
	gcall.Stepto(-35485, -37445, -379);
	gcall.Stepto(-35307, -37267, -379);
	gcall.Stepto(-35141, -37083, -394);
	gcall.Stepto(-35003, -36877, -434);
	gcall.Stepto(-34873, -36666, -477);
	gcall.Stepto(-34745, -36453, -521);
	gcall.Stepto(-34637, -36230, -574);
	gcall.Stepto(-34550, -35998, -650);
	gcall.Stepto(-34494, -35756, -886);
	gcall.Stepto(-34443, -35514, -1059);
	gcall.Stepto(-34409, -35275, -1081);
	gcall.Stepto(-34413, -35022, -1126);
	gcall.Stepto(-34360, -34785, -1179);
	gcall.Stepto(-34313, -34538, -1195);
	gcall.Stepto(-34267, -34294, -1170);
	gcall.Stepto(-34222, -34050, -1187);
	gcall.Stepto(-34187, -33808, -1256);
	gcall.Stepto(-34153, -33562, -1328);
	gcall.Stepto(-34097, -33320, -1359);
	gcall.Stepto(-34038, -33079, -1380);
	gcall.Stepto(-33962, -32843, -1387);
	gcall.Stepto(-33885, -32607, -1393);
	gcall.Stepto(-33808, -32369, -1428);
	gcall.Stepto(-33732, -32134, -1440);
	gcall.Stepto(-33655, -31898, -1421);
	gcall.Stepto(-33580, -31666, -1364);
	gcall.Stepto(-33502, -31425, -1342);
	gcall.Stepto(-33426, -31190, -1355);
	gcall.Stepto(-33349, -30953, -1365);
	gcall.Stepto(-33257, -30723, -1381);
	gcall.Stepto(-33161, -30495, -1379);
	gcall.Stepto(-33069, -30265, -1365);
	gcall.Stepto(-32976, -30034, -1335);
	gcall.Stepto(-32883, -29802, -1310);
	gcall.Stepto(-32791, -29576, -1292);
	gcall.Stepto(-32698, -29343, -1285);
	gcall.Stepto(-32605, -29114, -1281);
	gcall.Stepto(-32518, -28897, -1279);
	gcall.Stepto(-32420, -28652, -1283);
	gcall.Stepto(-32327, -28422, -1289);
	gcall.Stepto(-32233, -28193, -1284);
	gcall.Stepto(-32143, -27974, -1272);
	gcall.Stepto(-32044, -27733, -1261);
	gcall.Stepto(-31949, -27504, -1239);
	gcall.Stepto(-31852, -27273, -1214);
	gcall.Stepto(-31756, -27044, -1196);
	gcall.Stepto(-31660, -26815, -1172);
	gcall.Stepto(-31563, -26586, -1146);
	gcall.Stepto(-31461, -26359, -1105);
	gcall.Stepto(-31360, -26132, -1083);
	gcall.Stepto(-31260, -25908, -1046);
	gcall.Stepto(-31157, -25678, -1004);
	gcall.Stepto(-31063, -25468, -994);
	gcall.Stepto(-31063, -25467, -994);
	gcall.Stepto(-31094, -25448, -994);
	gcall.Stepto(-31304, -25319, -999);
	gcall.Stepto(-31517, -25189, -1006);
	gcall.Stepto(-31730, -25059, -1015);
	gcall.Stepto(-31940, -24930, -1024);
	gcall.Stepto(-32152, -24801, -1032);
	gcall.Stepto(-32364, -24689, -1029);
	gcall.Stepto(-32622, -24667, -1043);
	gcall.Stepto(-32868, -24692, -1070);
	gcall.Stepto(-33116, -24712, -1097);
	gcall.Stepto(-33364, -24714, -1123);
	gcall.Stepto(-33612, -24715, -1142);
	gcall.Stepto(-33860, -24717, -1158);
	gcall.Stepto(-34108, -24718, -1176);
	gcall.Stepto(-34360, -24719, -1181);
	gcall.Stepto(-34609, -24721, -1188);
	gcall.Stepto(-34857, -24722, -1202);
	gcall.Stepto(-35104, -24735, -1221);
	gcall.Stepto(-35343, -24800, -1237);
	gcall.Stepto(-35576, -24883, -1239);
	gcall.Stepto(-35809, -24971, -1289);
	gcall.Stepto(-36043, -25065, -1338);
	gcall.Stepto(-36270, -25157, -1392);
	gcall.Stepto(-36504, -25251, -1431);
	gcall.Stepto(-36734, -25344, -1459);
	gcall.Stepto(-36965, -25438, -1479);
	gcall.Stepto(-37196, -25531, -1504);
	gcall.Stepto(-37383, -25429, -1515);
	gcall.Stepto(-37552, -25247, -1524);
	gcall.Stepto(-37732, -25077, -1541);
	gcall.Stepto(-37913, -24907, -1548);
	gcall.Stepto(-38093, -24737, -1557);
	gcall.Stepto(-38277, -24565, -1554);
	gcall.Stepto(-38458, -24395, -1536);
	gcall.Stepto(-38639, -24225, -1491);
	gcall.Stepto(-38821, -24057, -1431);
	gcall.Stepto(-39004, -23890, -1394);
	gcall.Stepto(-39190, -23719, -1397);
	gcall.Stepto(-39164, -23492, -1364);
	gcall.Stepto(-39078, -23261, -1372);
	gcall.Stepto(-39007, -23055, -1362);
	gcall.NewSpend(1);
	Sleep(2000);
	//进副本结束

}
void TaskScript::Lianji6()
{
	//死亡
	if (gcall.GetPlayerDeadStatus() == 1 ||
		gcall.GetPlayerDeadStatus() == 2)
	{
		gcall.FuHuo();
		Sleep(3000);
		gcall.Stepto(-38753, -22648, -1377);
		gcall.Stepto(-38879, -22851, -1341);
		gcall.Stepto(-38939, -22910, -1329);
	}
	_BAGSTU stu;
	gcall.GetGoodsByEquipPos(EQUITMENT_POS::WUQI, &stu);
	if (stu.m_Lasting < 10)
	{
		gcall.NewSpend(2.5);
		gcall.Stepto(-38983, -22977, -1342);
		gcall.Stepto(-39017, -23073, -1367);
		gcall.Stepto(-39098, -23304, -1370);
		gcall.Stepto(-39135, -23549, -1368);
		gcall.Stepto(-39075, -23789, -1395);
		gcall.Stepto(-38936, -23985, -1411);
		gcall.Stepto(-38743, -24117, -1452);
		gcall.Stepto(-38394, -24371, -1542);
		gcall.Stepto(-38020, -24593, -1537);
		gcall.Stepto(-37642, -24806, -1507);
		gcall.Stepto(-37262, -25013, -1477);
		gcall.Stepto(-36874, -25212, -1475);
		gcall.Stepto(-36479, -25388, -1414);
		gcall.Stepto(-36083, -25562, -1315);
		gcall.Stepto(-35684, -25739, -1235);
		gcall.Stepto(-35292, -25911, -1220);
		gcall.Stepto(-34889, -26087, -1231);
		gcall.Stepto(-34479, -26227, -1231);
		gcall.Stepto(-34057, -26326, -1207);
		gcall.Stepto(-33626, -26378, -1162);
		gcall.Stepto(-33193, -26352, -1115);
		gcall.Stepto(-32865, -26314, -1101);
		gcall.Stepto(-32625, -26255, -1094);
		gcall.Stepto(-32385, -26193, -1084);
		gcall.Stepto(-32145, -26131, -1073);
		gcall.Stepto(-31905, -26065, -1069);
		gcall.Stepto(-31667, -25998, -1072);
		gcall.Stepto(-31428, -25931, -1063);
		gcall.Stepto(-31194, -25849, -1017);
		gcall.Stepto(-31057, -25757, -996);
		gcall.Stepto(-30888, -25573, -990);
		gcall.Stepto(-30712, -25399, -986);
		gcall.Stepto(-30639, -25438, -988);
		gcall.Stepto(-30550, -25517, -990);
		gcall.Stepto(-30571, -25434, -987);
		gcall.Stepto(-30594, -25575, -991);
		gcall.NewSpend(1);
		Sleep(1000);
		gcall.FixWuqi();
		Sleep(1000);
		gcall.NewSpend(2.5);
		gcall.Stepto(-30580, -25474, -990);
		gcall.Stepto(-30681, -25449, -989);
		gcall.Stepto(-30917, -25372, -981);
		gcall.Stepto(-31054, -25325, -987);
		gcall.Stepto(-31435, -25219, -1002);
		gcall.Stepto(-31857, -25112, -1023);
		gcall.Stepto(-32280, -25007, -1042);
		gcall.Stepto(-32687, -24906, -1058);
		gcall.Stepto(-33122, -24798, -1097);
		gcall.Stepto(-33539, -24695, -1137);
		gcall.Stepto(-33964, -24592, -1162);
		gcall.Stepto(-34397, -24556, -1178);
		gcall.Stepto(-34830, -24576, -1203);
		gcall.Stepto(-35253, -24662, -1229);
		gcall.Stepto(-35674, -24766, -1242);
		gcall.Stepto(-36100, -24845, -1324);
		gcall.Stepto(-36536, -24841, -1429);
		gcall.Stepto(-36961, -24763, -1453);
		gcall.Stepto(-37385, -24667, -1464);
		gcall.Stepto(-37626, -24606, -1480);
		gcall.Stepto(-37859, -24521, -1505);
		gcall.Stepto(-38087, -24427, -1542);
		gcall.Stepto(-38317, -24333, -1544);
		gcall.Stepto(-38546, -24238, -1504);
		gcall.Stepto(-38775, -24144, -1454);
		gcall.Stepto(-38981, -24006, -1409);
		gcall.Stepto(-39116, -23801, -1396);
		gcall.Stepto(-39182, -23565, -1393);
		gcall.Stepto(-39128, -23330, -1370);
		gcall.Stepto(-39015, -23141, -1377);
		gcall.Stepto(-38939, -22910, -1329);
		gcall.NewSpend(1);
		Sleep(1500);
	}

	if (gcall.GetBagGridNumberLast() < 5)
	{
		gcall.NewSpend(2.5);
		gcall.Stepto(-38983, -22977, -1342);
		gcall.Stepto(-39017, -23073, -1367);
		gcall.Stepto(-39098, -23304, -1370);
		gcall.Stepto(-39135, -23549, -1368);
		gcall.Stepto(-39075, -23789, -1395);
		gcall.Stepto(-38936, -23985, -1411);
		gcall.Stepto(-38743, -24117, -1452);
		gcall.Stepto(-38394, -24371, -1542);
		gcall.Stepto(-38020, -24593, -1537);
		gcall.Stepto(-37642, -24806, -1507);
		gcall.Stepto(-37262, -25013, -1477);
		gcall.Stepto(-36874, -25212, -1475);
		gcall.Stepto(-36479, -25388, -1414);
		gcall.Stepto(-36083, -25562, -1315);
		gcall.Stepto(-35684, -25739, -1235);
		gcall.Stepto(-35292, -25911, -1220);
		gcall.Stepto(-34889, -26087, -1231);
		gcall.Stepto(-34479, -26227, -1231);
		gcall.Stepto(-34057, -26326, -1207);
		gcall.Stepto(-33626, -26378, -1162);
		gcall.Stepto(-33193, -26352, -1115);
		gcall.Stepto(-32865, -26314, -1101);
		gcall.Stepto(-32625, -26255, -1094);
		gcall.Stepto(-32385, -26193, -1084);
		gcall.Stepto(-32145, -26131, -1073);
		gcall.Stepto(-31905, -26065, -1069);
		gcall.Stepto(-31667, -25998, -1072);
		gcall.Stepto(-31428, -25931, -1063);
		gcall.Stepto(-31194, -25849, -1017);
		gcall.Stepto(-31057, -25757, -996);
		gcall.Stepto(-30888, -25573, -990);
		gcall.Stepto(-30712, -25399, -986);
		gcall.Stepto(-30639, -25438, -988);
		gcall.Stepto(-30550, -25517, -990);
		gcall.Stepto(-30550, -25517, -990);
		gcall.Stepto(-30475, -25619, -991);
		gcall.NewSpend(1);
		Sleep(1000);
		gcall.SellItemByConfig(L"이화상");
		Sleep(1000);
		gcall.NewSpend(2.5);
		gcall.Stepto(-30580, -25474, -990);
		gcall.Stepto(-30681, -25449, -989);
		gcall.Stepto(-30917, -25372, -981);
		gcall.Stepto(-31054, -25325, -987);
		gcall.Stepto(-31435, -25219, -1002);
		gcall.Stepto(-31857, -25112, -1023);
		gcall.Stepto(-32280, -25007, -1042);
		gcall.Stepto(-32687, -24906, -1058);
		gcall.Stepto(-33122, -24798, -1097);
		gcall.Stepto(-33539, -24695, -1137);
		gcall.Stepto(-33964, -24592, -1162);
		gcall.Stepto(-34397, -24556, -1178);
		gcall.Stepto(-34830, -24576, -1203);
		gcall.Stepto(-35253, -24662, -1229);
		gcall.Stepto(-35674, -24766, -1242);
		gcall.Stepto(-36100, -24845, -1324);
		gcall.Stepto(-36536, -24841, -1429);
		gcall.Stepto(-36961, -24763, -1453);
		gcall.Stepto(-37385, -24667, -1464);
		gcall.Stepto(-37626, -24606, -1480);
		gcall.Stepto(-37859, -24521, -1505);
		gcall.Stepto(-38087, -24427, -1542);
		gcall.Stepto(-38317, -24333, -1544);
		gcall.Stepto(-38546, -24238, -1504);
		gcall.Stepto(-38775, -24144, -1454);
		gcall.Stepto(-38981, -24006, -1409);
		gcall.Stepto(-39116, -23801, -1396);
		gcall.Stepto(-39182, -23565, -1393);
		gcall.Stepto(-39128, -23330, -1370);
		gcall.Stepto(-39015, -23141, -1377);
		gcall.Stepto(-38939, -22910, -1329);
		gcall.NewSpend(1);
		Sleep(1500);
	}
	gcall.Stepto(-38858, -22737, -1353,120);
	gcall.Stepto(-38797, -22584, -1386,120);
	//MessageBox(0, 0, 0, MB_OK);
	//gcall.Stepto(-38705, -22354, -1455);
	/*
	gcall.Stepto(-38615, -22123, -1476);
	gcall.Stepto(-38573, -21881, -1444);
	gcall.Stepto(-38639, -21643, -1401);
	gcall.Stepto(-38759, -21427, -1348);
	gcall.Stepto(-38957, -21281, -1270);
	gcall.Stepto(-39173, -21151, -1190);
	gcall.Stepto(-39386, -21024, -1098);
	gcall.Stepto(-39600, -20899, -999);
	gcall.Stepto(-39820, -20786, -954);
	gcall.Stepto(-40042, -20675, -933);
	gcall.Stepto(-40263, -20564, -934);
	gcall.Stepto(-40475, -20435, -935);*/
	//MessageBox(0, L"摇奖完", L"装八卦", MB_OK);
	Sleep(1000);
	gcall.Shunyi(L"Lianji6");
	Sleep(2000);
	gcall.Stepto(-40539, -20262, -935);
	gcall.Stepto(-40684, -20145, -933);
	gcall.Stepto(-40806, -20005, -931);
	gcall.Stepto(-40906, -19848, -928);
	gcall.Stepto(-41005, -19689, -926);
	gcall.Stepto(-41105, -19532, -926);
	gcall.Stepto(-41204, -19374, -929);
	gcall.Stepto(-41310, -19221, -928);
	gcall.Stepto(-41436, -19082, -927);
	gcall.Stepto(-41603, -19008, -928);
	gcall.Stepto(-41787, -19026, -932);
	gcall.Stepto(-41917, -19152, -933);
	gcall.Stepto(-41929, -19335, -932);
	gcall.Stepto(-41885, -19516, -930);

	//gcall.FindThenKill(0, 1000, modeNormal | modeAoe | modeGoback | modePickup);
	

	

	if (gcall.FindThenKill(0, 1000, modeNormal | modeAoe | modePickup) == RESULT_KILL_PLAYDEAD)
	{
		gcall.FuHuo();
		Sleep(3000);
		gcall.Stepto(-38753, -22648, -1377);
		gcall.Stepto(-38879, -22851, -1341);
		gcall.Stepto(-38939, -22910, -1329);
	}
	else
	{
		gcall.Stepto(-41612, -19432, -932);
		Sleep(1000);
		/*
		MessageBox(0, 0, 0, MB_OK);
		gcall.Stepto(-41084, -19810, -928);
		gcall.Stepto(-40888, -19961, -930);
		gcall.Stepto(-40686, -20106, -932);
		gcall.Stepto(-40490, -20248, -935);
		gcall.Stepto(-40286, -20395, -934);
		gcall.Stepto(-40079, -20544, -932);
		gcall.Stepto(-39879, -20687, -937);
		gcall.Stepto(-39678, -20832, -971);
		gcall.Stepto(-39478, -20978, -1053);
		gcall.Stepto(-39278, -21125, -1158);
		gcall.Stepto(-39078, -21272, -1245);
		gcall.Stepto(-38879, -21419, -1328);
		gcall.Stepto(-38696, -21586, -1387);
		gcall.Stepto(-38613, -21817, -1430);
		gcall.Stepto(-38603, -22064, -1470);
		gcall.Stepto(-38662, -22305, -1461);
		gcall.Stepto(-38742, -22539, -1406);
		gcall.Stepto(-38861, -22756, -1351);
		gcall.Stepto(-38885, -22798, -1345);*/
		gcall.Shunyi(L"Lianji6-end");
		Sleep(2000);
	}

	//打怪完
	//延时(5000);
	gcall.HeChengWuQi(EQUITMENT_POS::WUQI);
	Sleep(500);
	gcall.BuqiBaGua(L"충각 치명보패");
	Sleep(500);
	//gcall.TihuanBaGua(L"");
	gcall.FenJieByConfig();
	Sleep(4000);
	gcall.Stepto(-38939, -22910, -1329,120);
	//整理背包();
	Sleep(4000);

}

void TaskScript::lianji8_go()
{
	gcall.NewSpend(2.5);
	gcall.Stepto(-36781, -38069, -379);
	gcall.Stepto(-36586, -37994, -360);
	gcall.Stepto(-36352, -37901, -374);
	gcall.Stepto(-36122, -37809, -373);
	gcall.Stepto(-35892, -37717, -359);
	gcall.Stepto(-35668, -37611, -376);
	gcall.Stepto(-35456, -37481, -379);
	gcall.Stepto(-35254, -37345, -379);
	gcall.Stepto(-35065, -37178, -395);
	gcall.Stepto(-34943, -36966, -426);
	gcall.Stepto(-34883, -36730, -465);
	gcall.Stepto(-34905, -36481, -524);
	gcall.Stepto(-34975, -36247, -591);
	gcall.Stepto(-35160, -36075, -660);
	gcall.Stepto(-35348, -35914, -761);
	gcall.Stepto(-35486, -35710, -866);
	gcall.Stepto(-35414, -35491, -936);
	gcall.Stepto(-35178, -35440, -978);
	gcall.Stepto(-34930, -35451, -1012);
	gcall.Stepto(-34692, -35458, -1032);
	gcall.Stepto(-34433, -35448, -1069);
	gcall.Stepto(-34191, -35407, -1102);
	gcall.Stepto(-33986, -35273, -1131);
	gcall.Stepto(-33767, -35151, -1154);
	gcall.Stepto(-33541, -35044, -1156);
	gcall.Stepto(-33318, -34938, -1141);
	gcall.Stepto(-33093, -34832, -1115);
	gcall.Stepto(-32868, -34725, -1082);
	gcall.Stepto(-32645, -34620, -1051);
	gcall.Stepto(-32419, -34513, -1012);
	gcall.Stepto(-32193, -34406, -973);
	gcall.Stepto(-31969, -34300, -955);
	gcall.Stepto(-31747, -34196, -926);
	gcall.Stepto(-31536, -34068, -889);
	gcall.Stepto(-31337, -33918, -846);
	gcall.Stepto(-31140, -33766, -790);
	gcall.Stepto(-30953, -33600, -756);
	gcall.Stepto(-30849, -33396, -736);
	gcall.Stepto(-30750, -33157, -728);
	gcall.Stepto(-30657, -32918, -708);
	gcall.Stepto(-30567, -32685, -688);
	gcall.Stepto(-30480, -32458, -684);
	gcall.Stepto(-30397, -32221, -716);
	gcall.Stepto(-30365, -31977, -769);
	gcall.Stepto(-30353, -31727, -841);
	gcall.Stepto(-30350, -31474, -916);
	gcall.Stepto(-30351, -31229, -978);
	gcall.Stepto(-30352, -30981, -1039);
	gcall.Stepto(-30353, -30731, -1096);
	gcall.Stepto(-30361, -30481, -1139);
	gcall.Stepto(-30369, -30233, -1167);
	gcall.Stepto(-30390, -29984, -1184);
	gcall.Stepto(-30423, -29737, -1192);
	gcall.Stepto(-30462, -29492, -1186);
	gcall.Stepto(-30511, -29252, -1179);
	gcall.Stepto(-30562, -29004, -1176);
	gcall.Stepto(-30610, -28765, -1173);
	gcall.Stepto(-30657, -28516, -1173);
	gcall.Stepto(-30702, -28279, -1174);
	gcall.Stepto(-30751, -28029, -1180);
	gcall.Stepto(-30815, -27789, -1189);
	gcall.Stepto(-30882, -27551, -1194);
	gcall.Stepto(-30950, -27309, -1192);
	gcall.Stepto(-31016, -27072, -1186);
	gcall.Stepto(-31084, -26830, -1160);
	gcall.Stepto(-31150, -26593, -1152);
	gcall.Stepto(-31217, -26354, -1110);
	gcall.Stepto(-31271, -26109, -1077);
	gcall.Stepto(-31285, -25861, -1043);
	gcall.Stepto(-31250, -25616, -1008);
	gcall.Stepto(-31194, -25374, -996);
	gcall.Stepto(-31138, -25131, -985);
	gcall.Stepto(-31079, -24889, -977);
	gcall.Stepto(-31021, -24647, -974);
	gcall.Stepto(-30962, -24403, -968);
	gcall.Stepto(-30904, -24163, -961);
	gcall.Stepto(-30846, -23923, -957);
	gcall.Stepto(-30803, -23678, -965);
	gcall.Stepto(-30771, -23429, -992);
	gcall.Stepto(-30740, -23184, -1024);
	gcall.Stepto(-30708, -22936, -1039);
	gcall.Stepto(-30676, -22691, -1036);
	gcall.Stepto(-30644, -22443, -1040);
	gcall.Stepto(-30613, -22197, -1051);
	gcall.Stepto(-30582, -21959, -1040);
	gcall.Stepto(-30552, -21718, -1017);
	gcall.Stepto(-30477, -21479, -991);
	gcall.Stepto(-30371, -21252, -976);
	gcall.Stepto(-30230, -21050, -964);
	gcall.Stepto(-30073, -20857, -941);
	gcall.Stepto(-29912, -20673, -924);
	gcall.Stepto(-29740, -20483, -905);
	gcall.Stepto(-29575, -20302, -900);
	gcall.Stepto(-29412, -20111, -896);
	gcall.Stepto(-29306, -19889, -897);
	gcall.Stepto(-29297, -19639, -899);
	gcall.Stepto(-29327, -19393, -909);
	gcall.Stepto(-29375, -19149, -908);
	gcall.Stepto(-29428, -18905, -918);
	gcall.Stepto(-29484, -18664, -924);
	gcall.Stepto(-29540, -18422, -917);
	gcall.Stepto(-29605, -18183, -898);
	gcall.Stepto(-29670, -17949, -879);
	gcall.Stepto(-29714, -17698, -846);
	gcall.Stepto(-29715, -17446, -810);
	gcall.Stepto(-29699, -17199, -795);
	gcall.Stepto(-29660, -16954, -756);
	gcall.Stepto(-29623, -16711, -712);
	gcall.Stepto(-29619, -16682, -711);
	gcall.Stepto(-29563, -16312, -695);
	gcall.NewSpend(1);
	Sleep(2000);
}
void TaskScript::lianji8()
{
	//死亡
	if (gcall.GetPlayerDeadStatus() == 1 ||
		gcall.GetPlayerDeadStatus() == 2)
	{
		gcall.FuHuo();
		Sleep(3000);
		gcall.Stepto(-29719, -14670, -1237);
		gcall.Stepto(-29689, -15176, -975);
		gcall.Stepto(-29633, -15683, -748);
	}

	//修理
	_BAGSTU stu;
	gcall.GetGoodsByEquipPos(EQUITMENT_POS::WUQI, &stu);
	if (stu.m_Lasting < 10)
	{
		gcall.NewSpend(2.5);
		gcall.Stepto(-29574, -16320, -694);
		gcall.Stepto(-29573, -16476, -683);
		gcall.Stepto(-29699, -16892, -754);
		gcall.Stepto(-29916, -17493, -856);
		gcall.Stepto(-30209, -18196, -957);
		gcall.Stepto(-30340, -18508, -933);
		gcall.Stepto(-30503, -18897, -906);
		gcall.Stepto(-30703, -19413, -919);
		gcall.Stepto(-30790, -19655, -932);
		gcall.Stepto(-30828, -19931, -933);
		gcall.Stepto(-30986, -20091, -938);
		gcall.Stepto(-30985, -20750, -958);
		gcall.Stepto(-30971, -21568, -1003);
		gcall.Stepto(-30964, -22182, -1062);
		gcall.Stepto(-30944, -23093, -1046);
		gcall.Stepto(-30985, -23981, -949);
		gcall.Stepto(-31040, -24867, -976);
		gcall.Stepto(-31012, -25240, -981);
		gcall.Stepto(-30921, -25312, -978);
		gcall.Stepto(-30714, -25477, -990);
		gcall.Stepto(-30564, -25579, -991);
		gcall.NewSpend(1);
		Sleep(1000);
		gcall.FixWuqi();
		Sleep(1000);
		gcall.NewSpend(2.5);
		gcall.Stepto(-30509,-25615,-991);
		gcall.Stepto(-30690,-25465,-990);
		gcall.Stepto(-30889,-25317,-977);
		gcall.Stepto(-31089,-25171,-983);
		gcall.Stepto(-31108,-24930,-978);
		gcall.Stepto(-31119,-24682,-971);
		gcall.Stepto(-31125,-24433,-957);
		gcall.Stepto(-31131,-24185,-940);
		gcall.Stepto(-31145,-23938,-950);
		gcall.Stepto(-31173,-23690,-971);
		gcall.Stepto(-31201,-23443,-1001);
		gcall.Stepto(-31228,-23197,-1029);
		gcall.Stepto(-31238,-22949,-1034);
		gcall.Stepto(-31243,-22701,-1029);
		gcall.Stepto(-31233,-22453,-1031);
		gcall.Stepto(-31224,-22205,-1049);
		gcall.Stepto(-31216,-21957,-1048);
		gcall.Stepto(-31214,-21709,-1031);
		gcall.Stepto(-31218,-21461,-1005);
		gcall.Stepto(-31223,-21213,-980);
		gcall.Stepto(-31232,-20965,-961);
		gcall.Stepto(-31251,-20718,-947);
		gcall.Stepto(-31279,-20472,-931);
		gcall.Stepto(-31310,-20226,-921);
		gcall.Stepto(-31337,-19979,-909);
		gcall.Stepto(-31294,-19737,-912);
		gcall.Stepto(-31179,-19551,-916);
		gcall.Stepto(-31038,-19348,-911);
		gcall.Stepto(-30898,-19142,-894);
		gcall.Stepto(-30773,-18929,-902);
		gcall.Stepto(-30671,-18750,-926);
		gcall.Stepto(-30563,-18561,-943);
		gcall.Stepto(-30464,-18384,-953);
		gcall.Stepto(-30347,-18165,-959);
		gcall.Stepto(-30231,-17946,-954);
		gcall.Stepto(-30126,-17750,-934);
		gcall.Stepto(-30009,-17531,-884);
		gcall.Stepto(-29893,-17312,-836);
		gcall.Stepto(-29776,-17093,-797);
		gcall.Stepto(-29680,-16865,-745);
		gcall.Stepto(-29623,-16623,-676);
		gcall.Stepto(-29594,-16408,-687);
		gcall.NewSpend(1);
		Sleep(3000);
	}

	//卖
	if (gcall.GetBagGridNumberLast() < 5)
	{
		gcall.NewSpend(2.5);
		gcall.Stepto(-29595, -16286, -696);
		gcall.Stepto(-29604, -16328, -692);
		gcall.Stepto(-29666, -16604, -674);
		gcall.Stepto(-29890, -17342, -837);
		gcall.Stepto(-30329, -18364, -947);
		gcall.Stepto(-31004, -19852, -937);
		gcall.Stepto(-31053, -20283, -939);
		gcall.Stepto(-31044, -21059, -964);
		gcall.Stepto(-31030, -23412, -995);
		gcall.Stepto(-31011, -24341, -960);
		gcall.Stepto(-31185, -25175, -989);
		gcall.Stepto(-30972, -25401, -986);
		gcall.Stepto(-30573, -25571, -991);
		gcall.Stepto(-30545, -25594, -991);
		gcall.Stepto(-30545, -25594, -991);
		gcall.NewSpend(1);
		Sleep(1000);
		gcall.SellItemByConfig(L"이화상");
		Sleep(1000);
		gcall.NewSpend(2.5);
		gcall.Stepto(-30509,-25615,-991);
		gcall.Stepto(-30690,-25465,-990);
		gcall.Stepto(-30889,-25317,-977);
		gcall.Stepto(-31089,-25171,-983);
		gcall.Stepto(-31108,-24930,-978);
		gcall.Stepto(-31119,-24682,-971);
		gcall.Stepto(-31125,-24433,-957);
		gcall.Stepto(-31131,-24185,-940);
		gcall.Stepto(-31145,-23938,-950);
		gcall.Stepto(-31173,-23690,-971);
		gcall.Stepto(-31201,-23443,-1001);
		gcall.Stepto(-31228,-23197,-1029);
		gcall.Stepto(-31238,-22949,-1034);
		gcall.Stepto(-31243,-22701,-1029);
		gcall.Stepto(-31233,-22453,-1031);
		gcall.Stepto(-31224,-22205,-1049);
		gcall.Stepto(-31216,-21957,-1048);
		gcall.Stepto(-31214,-21709,-1031);
		gcall.Stepto(-31218,-21461,-1005);
		gcall.Stepto(-31223,-21213,-980);
		gcall.Stepto(-31232,-20965,-961);
		gcall.Stepto(-31251,-20718,-947);
		gcall.Stepto(-31279,-20472,-931);
		gcall.Stepto(-31310,-20226,-921);
		gcall.Stepto(-31337,-19979,-909);
		gcall.Stepto(-31294,-19737,-912);
		gcall.Stepto(-31179,-19551,-916);
		gcall.Stepto(-31038,-19348,-911);
		gcall.Stepto(-30898,-19142,-894);
		gcall.Stepto(-30773,-18929,-902);
		gcall.Stepto(-30671,-18750,-926);
		gcall.Stepto(-30563,-18561,-943);
		gcall.Stepto(-30464,-18384,-953);
		gcall.Stepto(-30347,-18165,-959);
		gcall.Stepto(-30231,-17946,-954);
		gcall.Stepto(-30126,-17750,-934);
		gcall.Stepto(-30009,-17531,-884);
		gcall.Stepto(-29893,-17312,-836);
		gcall.Stepto(-29776,-17093,-797);
		gcall.Stepto(-29680,-16865,-745);
		gcall.Stepto(-29623,-16623,-676);
		gcall.Stepto(-29594,-16408,-687);
		gcall.NewSpend(1);
		Sleep(3000);
	}

	gcall.Stepto(-29591 , -16081 , -709,120);
	gcall.Stepto(-29619 , -15749 , -739,120);
	//瞬移
	Sleep(1000);
	gcall.Shunyi(L"Lianji8");
	Sleep(2000);
	gcall.Stepto(-32935, -14344, -1650);
	//引怪
	gcall.Stepto(-33182, -14357, -1697);
	gcall.Stepto(-33433, -14355, -1704);
	gcall.Stepto(-33635, -14358, -1704);
	gcall.Stepto(-33837, -14360, -1704);
	gcall.Stepto(-34040, -14363, -1704);
	gcall.Stepto(-34243, -14365, -1704);
	gcall.Stepto(-34492, -14368, -1704);
	gcall.Stepto(-34696, -14371, -1704);
	gcall.Stepto(-34898, -14373, -1704);
	gcall.Stepto(-35100, -14374, -1704);
	gcall.Stepto(-35302, -14370, -1704);
	gcall.Stepto(-35536, -14284, -1709);
	gcall.Stepto(-35698, -14099, -1709);
	gcall.Stepto(-35724, -13853, -1716);
	gcall.Stepto(-35711, -13651, -1716);
	gcall.Stepto(-35700, -13450, -1716);
	gcall.Stepto(-35687, -13246, -1709);
	gcall.Stepto(-35673, -13044, -1713);
	gcall.Stepto(-35613, -12850, -1713);
	gcall.Stepto(-35549, -12658, -1713);
	gcall.Stepto(-35489, -12463, -1713);
	gcall.Stepto(-35430, -12270, -1713);
	gcall.Stepto(-35331, -11989, -1713);
	gcall.sendcall(id_msg_attack, (LPVOID)0x5dca);
	gcall.Stepto(-35541, -12104, -1713);
	gcall.Stepto(-35713, -12207, -1713);
	gcall.Stepto(-35898, -12295, -1713);
	gcall.Stepto(-36081, -12376, -1713);
	gcall.Stepto(-36272, -12441, -1713);
	gcall.Stepto(-36475, -12447, -1707);
	gcall.Stepto(-36678, -12446, -1707);
	gcall.Stepto(-36879, -12442, -1612);
	gcall.Stepto(-37083, -12436, -1487);
	gcall.Stepto(-37287, -12431, -1416);
	gcall.Stepto(-37491, -12426, -1416);
	gcall.Stepto(-37695, -12424, -1416);
	gcall.Stepto(-37897, -12424, -1411);
	gcall.Stepto(-38101, -12425, -1411);
	gcall.Stepto(-38305, -12425, -1411);
	gcall.Stepto(-38509, -12426, -1409);
	gcall.Stepto(-38710, -12423, -1409);
	gcall.Stepto(-38910, -12421, -1409);
	if (gcall.FindThenKill(0, 1350, modeNormal | modeAoe | modePickup) == RESULT_KILL_PLAYDEAD)
	{
		gcall.FuHuo();
		Sleep(3000);
		gcall.Stepto(-29719, -14670, -1237);
		gcall.Stepto(-29689, -15176, -975);
		gcall.Stepto(-29633, -15683, -748);
	}
	else
	{
		_BAGSTU yaoshi;
		if (gcall.GetGoodsFromBagByName(L"제룡림 열쇠",&yaoshi))
		{
			gcall.Stepto(-39052, -12237, -1409);
			gcall.Stepto(-39249, -12029, -1409);
			gcall.Stepto(-39506, -11897, -1416);
			Sleep(500);
			gcall.PickupTask();
			Sleep(500);
		}
		gcall.Stepto(-39308, -11900, -1416);
		Sleep(1000);
		gcall.Shunyi(L"1-9-2");
		Sleep(2000);
	}

	//打怪完
	//延时(5000);
	gcall.HeChengWuQi(EQUITMENT_POS::WUQI);
	Sleep(500);
	gcall.BuqiBaGua(L"충각 치명보패");
	Sleep(500);
	gcall.FenJieByConfig();
	Sleep(4000);
	//走到门口的坐标
	gcall.Stepto(-29590, -16033, -713,120);
	gcall.Stepto(-29561, -16406, -689,120);
	Sleep(4000);
	
	

}
