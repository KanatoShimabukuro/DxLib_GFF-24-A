#include "SphereCollider.h"
#include <math.h>
#include <stdio.h>
#include "Common.h"


SphereCollider::SphereCollider()
{
    diff.x = 0;//�����Ƀv���C���[�̈ړ��ʂ�����
    diff.y = 0;
}

int SphereCollider::CheckCollision(SphereCollider sphereCollider)
{
    //�O�����̒藝���g��
    float a = (location.x + diff.x) - (sphereCollider.location.x + sphereCollider.diff.x);
    float b = (location.y + diff.y) - (sphereCollider.location.y + sphereCollider.diff.y);
    float c = sqrtf(a * a + b * b);

    //���ꂼ��̔��a�̍��v��2�_�Ԃ̋������ׂ�
    if (c <= radius + sphereCollider.radius) {
        return COLLISION;
    }
    return NO_COLLISION;
}