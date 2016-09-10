void StageAnimate(uint8 AnimationAmount, uint16* CurrentFrame, uint8* Ticks, float* OriginalAnimationFactor, float FactorBuildUp, uint8 TextureAmount, Speed) { \
\
AnimationFactor = OriginalAnimationFactor; \
\
if(AnimationFactor < 1.0f){ \
OriginalAnimationFactor += FactorBuildUp; \
if(OriginalAnimationFactor >= 1.0f){ \
OriginalAnimationFactor = 0.0f; \
AnimationFactor = 1.0f; \
} \
} \
\
if(AnimationFactor >= 1.0f){ \
do{ \
\
\
for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap<AnimationAmount; DirtyDeedsDoneDirtCheap++){ \
if(TextureAmount > 1){ \
\
\
\
Ticks++; \
if(Ticks >= Speed){ \
 \
Ticks = 0; \
CurrentFrame++; \
if(CurrentFrame >= TextureAmount){ \
\
CurrentFrame = 0; \
\
} \
} \
\
} \
} \
\
AnimationFactor-=1.0f; \
} while(AnimationFactor > 0.0f); \
} \
\
}