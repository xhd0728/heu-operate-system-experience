#include "EOSApp.h"

//
// main �������������壺
// argc - argv ����ĳ��ȣ���С����Ϊ 1��argc - 1 Ϊ�����в�����������
// argv - �ַ���ָ�����飬���鳤��Ϊ�����в������� + 1������ argv[0] �̶�ָ��ǰ
//        ������ִ�еĿ�ִ���ļ���·���ַ�����argv[1] ��������ָ��ָ�����������
//        ������
//        ����ͨ������������ "a:\hello.exe -a -b" �������̺�hello.exe �� main ��
//        ���Ĳ��� argc ��ֵΪ 3��argv[0] ָ���ַ��� "a:\hello.exe"��argv[1] ָ��
//        �����ַ��� "-a"��argv[2] ָ������ַ��� "-b"��
//
int main(int argc, char* argv[])
{
	//
	// �����Ҫ�ڵ���Ӧ�ó���ʱ�ܹ����Խ����ں˲���ʾ��Ӧ��Դ�룬
	// ����ʹ�� EOS �ں���Ŀ����������ȫ�汾�� SDK �ļ��У�Ȼ
	// ��ʹ�øո����ɵ� SDK �ļ��и��Ǵ�Ӧ�ó�����Ŀ�е� SDK �ļ�
	// �У����� EOS �ں���Ŀ�ڴ����ϵ�λ�ò��ܸı䡣
	//

	/* TODO: �ڴ˴�����Լ��Ĵ��� */
	//printf("Hello world!\n");
	INT *d;
	//
	// ����API����VirtualAlloc��
	// ����һ�����ͱ�������Ŀռ䣬
	// ����һ�����ͱ�����ָ��ָ������ռ�
	//
	if (d = VirtualAlloc(0, sizeof(int), MEM_RESERVE|MEM_COMMIT)) {
		printf("Allocated %d bytes virtual memory of 0x%x \n\n", *d);
		//
		// �޸����ͱ�����ֵΪ0xFFFFFFFF
		// ���޸�ǰ������ͱ�����ֵ�������޸ĺ�������ͱ�����ֵ
		//
		printf("virtual memory original value: 0x%x\n\n", *d);
		*d = 0xFFFFFFFF;
		printf("a new virtual memory value: 0x%x\n\n", *d);
		//
		// ����API�����ȴ�10��
		//
		Sleep(10000);
		//
		// ����API����VirtualFree,
		// �ͷ�֮ǰ��������ͱ����Ŀռ�
		//
		if (VirtualFree(d, 0, MEM_RELEASE)) {
			printf("release virtualmemory success!\n");
		} else {
			printf("release error\n");
		}
		//
		// ������ѭ��
		//
		printf("endless loop start");
		for(;;);
	} else {
		printf("error\n");
		return -1;
	}
	printf("program complete\n");
	return 0;
}
