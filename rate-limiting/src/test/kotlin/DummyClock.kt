import com.trackmyfamily.Clock

class DummyClock: Clock {

    var currTime: Long = 0L

    override fun getCurrentTimeMs() = currTime


}