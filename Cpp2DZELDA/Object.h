#pragma once
enum class ObjectType
{
	None,
	Player,
	Missile,
	Enemy,
};

class Object
{
public:
	Object(ObjectType type);
	virtual ~Object();

	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;

public:
	ObjectType GetType() { return _type; }
	Pos GetPos() { return _pos; }
	void SetPos(Pos pos) { _pos = pos; }

protected:
	ObjectType _type = ObjectType::None;
	Pos _pos = Pos(0, 0);
};

