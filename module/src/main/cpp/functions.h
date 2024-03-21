#ifndef ZYCHEATS_SGUYS_FUNCTIONS_H
#define ZYCHEATS_SGUYS_FUNCTIONS_H

// here you can define variables for the patches
bool noStoneCD;

monoString *CreateIl2cppString(const char *str) {
    monoString *(*String_CreateString)(void *instance, const char *str) = (monoString*(*)(void*, const char*)) (g_il2cppBaseMap.startAddress + string2Offset(OBFUSCATE("0x168B944")));
    return String_CreateString(NULL, str);
}

void Pointers() {
    
}

void Patches() {
    //PATCH_SWITCH("0x10A69A0", "200080D2C0035FD6", showAllItems);
    //PATCH_SWITCH("0xF148A4", "E07C80D2C0035FD6", freeItems);
}

// declare your hooks here
float (*FPSWeaponEquipment_get_FireRate)(void *instance);
float _FPSWeaponEquipment_get_FireRate(void *instance)
{
    if (instance != NULL)
    {
        if (noStoneCD)
        {
            LOGI("No Stone CD Active!")
            return 0.0f;
        }
    }
    return FPSWeaponEquipment_get_FireRate(instance)
}

void Hooks() {
    HOOK("0x21D0224", _FPSWeaponEquipment_get_FireRate, FPSWeaponEquipment_get_FireRate);
}

#endif //ZYCHEATS_SGUYS_FUNCTIONS_H


/*
// Dll : Assembly-CSharp.dll
// Namespace: 
public class FPSWeaponEquipment : FPSItemEquipment
{
	// Fields
	private CharacterSystem character; // 0x2c
	private FPSController fpsController; // 0x30
	private AudioSource audioSource; // 0x34
	private Animator animator; // 0x38
	public Boolean HoldFire; // 0x3c
	private Boolean animatorContainsKeyShootType; // 0x3d
	private Single _FireRate; // 0x40
	private Single _rate; // 0x44
	private Single _distance; // 0x48
	private Single _overlapDot; // 0x4c
	public Single Spread; // 0x50
	public Int32 BulletNum; // 0x54
	public Single Force; // 0x58
	public Vector2 KickPower; // 0x5c
	public Int32 MaxPenetrate; // 0x64
	public Int32 Ammo; // 0x68
	public Int32 AmmoMax; // 0x6c
	public Int32 ClipSize; // 0x70
	public AudioClip SoundFire; // 0x74
	public AudioClip SoundReload; // 0x78
	public AudioClip SoundReloadComplete; // 0x7c
	public AudioClip[] DamageSound; // 0x80
	public GameObject MuzzleFX; // 0x84
	public Transform MuzzlePoint; // 0x88
	public ItemData ItemUsed; // 0x8c
	public Int32 animationID; // 0x90
	public Boolean InfinityAmmo; // 0x94
	public Boolean OnAnimationEvent; // 0x95
	public Single panicfire; // 0x98
	public Single PanicFireMult; // 0x9c
	public Single FOVZoom; // 0xa0
	public Single SpreadZoomMult; // 0xa4
	public Boolean HideWhenZoom; // 0xa8
	public GameObject ProjectileFX; // 0xac
	private ObscuredFloat _moveDisableTime; // 0xb0
	private ObscuredFloat _shotDelay; // 0xc0
	private ResourceItem _resItem; // 0xd0
	private Boolean _inited; // 0xd4
	private Boolean reloading; // 0xd5
	private Single spreadmult; // 0xd8
	private readonly Vector3[] tempDirs; // 0xdc

	// Properties
	public ResourceItem resItem { get; }
	public ObscuredFloat MoveDisableTime { get; }
	public Single AttackAnimationScale { get; }
	public Single FireRate { get; }
	public Single Rate { get; }

	// Methods
	// RVA: 0x21d0138 VA: 0xc0e9e138
	public ResourceItem get_resItem() { }
	// RVA: 0x21d0140 VA: 0xc0e9e140
	public ObscuredFloat get_MoveDisableTime() { }
	// RVA: 0x21d0564 VA: 0xc0e9e564
	public Single get_AttackAnimationScale() { }
	// RVA: 0x21d0224 VA: 0xc0e9e224
	public Single get_FireRate() { }
	// RVA: 0x21d058c VA: 0xc0e9e58c
	public Single get_Rate() { }
	// RVA: 0x21d07f8 VA: 0xc0e9e7f8
	public Void Start() { }
	// RVA: 0x21d08b0 VA: 0xc0e9e8b0
	public override Void Init() { }
	// RVA: 0x21d0c2c VA: 0xc0e9ec2c
	public override Void Initialize(MovableUnit owner, UnitWeapon unitWeapon, UnitWeapon realUnitWeapon) { }
	// RVA: 0x21d13f8 VA: 0xc0e9f3f8
	public override Void Trigger() { }
	// RVA: 0x21d2210 VA: 0xc0ea0210
	public override Void OnTriggerRelease() { }
	// RVA: 0x21d2218 VA: 0xc0ea0218
	public override Void Trigger2() { }
	// RVA: 0x21d2220 VA: 0xc0ea0220
	public override Void OnTrigger2Release() { }
	// RVA: 0x21d194c VA: 0xc0e9f94c
	public Void Shoot() { }
	// RVA: 0x21d2228 VA: 0xc0ea0228
	public override Void Reload() { }
	// RVA: 0x21d2718 VA: 0xc0ea0718
	public override Void ReloadComplete() { }
	// RVA: 0x21d2938 VA: 0xc0ea0938
	public override Void DOLateUpdate() { }
	// RVA: 0x21d16fc VA: 0xc0e9f6fc
	private Boolean OnHandAction() { }
	// RVA: 0x21d2f28 VA: 0xc0ea0f28
	public override Void OnAction() { }
	// RVA: 0x21d43a8 VA: 0xc0ea23a8
	public override Void EnableMove() { }
	// RVA: 0x21d43e0 VA: 0xc0ea23e0
	public Void .ctor() { }
	// RVA: 0x21d44e4 VA: 0xc0ea24e4
	private Void <Shoot>b__55_0() { }
	// RVA: 0x21d4530 VA: 0xc0ea2530
	private Void <DOLateUpdate>b__60_0(Packet packet) { }
}
*/